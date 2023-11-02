/*++

Copyright (C) 2019 3MF Consortium

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract:

Vulometric.cpp: Defines Unittests for the Volumetric extension

--*/

#include "UnitTest_Utilities.h"
#include "lib3mf_implicit.hpp"

namespace Lib3MF
{
    namespace helper
    {
        PImplicitFunction createGyroidFunction(CModel& model)
        {
            PImplicitFunction gyroidFunction = model.AddImplicitFunction();

            gyroidFunction->SetDisplayName("gyroid");

            auto functionArgument = gyroidFunction->AddInput(
                "pos", "position", Lib3MF::eImplicitPortType::Vector);

            auto decomposePos = gyroidFunction->AddDecomposeVectorNode(
                "decomposePos", "decompose pos", "group_a");

            gyroidFunction->AddLinkByNames("inputs.pos", "decomposePos.A");

            auto composeYZX = gyroidFunction->AddComposeVectorNode(
                "composeYZX", "compose yzx", "group_a");

            auto composeYZXInputX = composeYZX->GetInputX();
            auto decomposePosOutputZ = decomposePos->GetOutputZ();
            gyroidFunction->AddLink(decomposePosOutputZ, composeYZXInputX);

            auto composeYZXInputY = composeYZX->GetInputY();
            auto decomposePosOutputY = decomposePos->GetOutputY();
            gyroidFunction->AddLink(decomposePosOutputY, composeYZXInputY);

            auto composeYZXInputZ = composeYZX->GetInputZ();
            auto decomposePosOutputX = decomposePos->GetOutputX();
            gyroidFunction->AddLink(decomposePosOutputX, composeYZXInputZ);

            // Add the nodes and links for the gyroid
            // (dot(sin(pos), cos(composeYZX))
            auto sinNode = gyroidFunction->AddSinNode(
                "sin", Lib3MF::eImplicitNodeConfiguration::VectorToVector,
                "sinus", "group_a");

            auto posArg = gyroidFunction->FindInput("pos");
            auto sinInputA = sinNode->GetInputA();
            gyroidFunction->AddLink(posArg, sinInputA);
            
            auto cosNode = gyroidFunction->AddCosNode(
                "cos", Lib3MF::eImplicitNodeConfiguration::VectorToVector,
                "cosinus", "group_a");
            
            auto cosInputA = cosNode->GetInputA();
            auto composeYZXOutput = composeYZX->GetOutputResult();
            gyroidFunction->AddLink(composeYZXOutput, cosInputA);

            auto dotNode =
                gyroidFunction->AddDotNode("dot", "dot product", "group_a");

            auto sinOutput = sinNode->GetOutputResult();
            auto dotInputA = dotNode->GetInputA();
            gyroidFunction->AddLink(sinOutput, dotInputA);

            auto cosOutput = cosNode->GetOutputResult();
            auto dotInputB = dotNode->GetInputB();
            gyroidFunction->AddLink(cosOutput, dotInputB);

            auto output = gyroidFunction->AddOutput(
                "shape", "signed distance to the surface",
                Lib3MF::eImplicitPortType::Scalar);

            auto dotOutput = dotNode->GetOutputResult();
            gyroidFunction->AddLink(dotOutput, output);

            return gyroidFunction;
        }

    }  // namespace helper

    class Volumetric : public ::testing::Test
    {
       protected:
        virtual void SetUp()
        {
            if(!helper::directoryExists(OutFolder))
            {
                ASSERT_TRUE(CreateDir(OutFolder.c_str()))
                    << L"Could not create folder.";
            }
            model = wrapper->CreateModel();
            loadPyramid();
            writer3MF = model->QueryWriter("3mf");
            writerSTL = model->QueryWriter("stl");
        }
        virtual void TearDown()
        {
            model.reset();
            writer3MF.reset();
            writerSTL.reset();
        }

        void loadPyramid()
        {
            model = wrapper->CreateModel();
            auto reader = model->QueryReader("3mf");
            reader->ReadFromFile(InFolder + "Pyramid.3mf");
        }

        PModel model;
        PWriter writer3MF;
        PWriter writerSTL;

        static std::string InFolder;
        static std::string OutFolder;

        static void SetUpTestCase() { wrapper = CWrapper::loadLibrary(); }
        static PWrapper wrapper;

        PImageStack SetupSheetsFromFile();
        PMeshObject GetMesh();
    };
    PWrapper Volumetric::wrapper;
    std::string Volumetric::InFolder(sTestFilesPath + "/Volumetric/");
    std::string Volumetric::OutFolder(sOutFilesPath + "/Volumetric/");

    PImageStack Volumetric::SetupSheetsFromFile()
    {
        PImageStack pImageStack = model->AddImageStack(821, 819, 11);
        for(int i = 0; i < 11; i++)
        {
            std::string sNumber = "_";
            int k = i + 1;
            if(k < 10)
            {
                sNumber = sNumber + "0";
            }
            sNumber = sNumber + std::to_string(k);

            pImageStack->CreateSheetFromFile(
                i, "/volume/layer" + sNumber + ".png",
                InFolder + "img" + sNumber + ".png");
        }
        return pImageStack;
    }

    PMeshObject Volumetric::GetMesh()
    {
        auto meshes = model->GetMeshObjects();
        meshes->MoveNext();
        return meshes->GetCurrentMeshObject();
    }

    TEST_F(Volumetric, AddFunction_NumberOfFunctionsIncreases)
    {
        auto resourceIteratorBefore = model->GetResources();
        EXPECT_EQ(resourceIteratorBefore->Count(), 2);
        auto functionIteratorBefore = model->GetFunctions();
        EXPECT_EQ(functionIteratorBefore->Count(), 0);
        PImplicitFunction newFunction = model->AddImplicitFunction();
        std::string const displayName = "test";
        newFunction->SetDisplayName(displayName);

        auto resourceIteratorAfter = model->GetResources();
        EXPECT_EQ(resourceIteratorAfter->Count(), 3);

        auto functionIterator = model->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        EXPECT_TRUE(functionIterator->MoveNext());
        EXPECT_EQ(functionIterator->GetCurrentFunction()->GetDisplayName(),
                  displayName);
        EXPECT_FALSE(functionIterator->MoveNext());
    }

    TEST_F(Volumetric, AddFunction_AddedFunctionAreWrittenTo3mfFile)
    {
        PImplicitFunction newFunction = model->AddImplicitFunction();
        std::string const displayName = "test";
        newFunction->SetDisplayName(displayName);
        auto const expectedResourceId = newFunction->GetModelResourceID();

        writer3MF->WriteToFile(Volumetric::OutFolder + "AddFunction.3mf");

        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder + "AddFunction.3mf");

        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        EXPECT_TRUE(functionIterator->MoveNext());
        EXPECT_EQ(functionIterator->GetCurrentFunction()->GetDisplayName(),
                  displayName);
        EXPECT_EQ(functionIterator->GetCurrentFunction()->GetModelResourceID(),
                  expectedResourceId);
        EXPECT_FALSE(functionIterator->MoveNext());
    }

    // Function with an "addition" node
    TEST_F(Volumetric,
           AddFunction_AddedFunctionWithAdditionNodeAreWrittenTo3mfFile)
    {
        PImplicitFunction newFunction = model->AddImplicitFunction();
        std::string const displayName = "test";
        newFunction->SetDisplayName(displayName);
        auto const expectedResourceId = newFunction->GetModelResourceID();

        // Add an addition node
        auto node = newFunction->AddAdditionNode(
            "addition_1", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "addition 1", "group_a");

        // Check if the node is added
        {
            auto nodeIterator = newFunction->GetNodes();
            ASSERT_EQ(nodeIterator->Count(), 1);
            EXPECT_TRUE(nodeIterator->MoveNext());
            EXPECT_EQ(nodeIterator->GetCurrent()->GetIdentifier(),
                      node->GetIdentifier());
        }
        // Write to file
        writer3MF->WriteToFile(Volumetric::OutFolder +
                               "AddFunctionWithAdditionNode.3mf");

        // Read from file
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder +
                               "AddFunctionWithAdditionNode.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        // // Check the addtion node
        EXPECT_TRUE(functionIterator->MoveNext());
        EXPECT_EQ(functionIterator->GetCurrentFunction()->GetModelResourceID(),
                  expectedResourceId);

        PImplicitFunction currentImplicitFunction =
            std::dynamic_pointer_cast<CImplicitFunction>(
                functionIterator->GetCurrentFunction());
        ASSERT_NE(currentImplicitFunction, nullptr);

        auto nodeIterator = currentImplicitFunction->GetNodes();
        ASSERT_EQ(nodeIterator->Count(), 1);
        EXPECT_TRUE(nodeIterator->MoveNext());
        EXPECT_EQ(nodeIterator->GetCurrent()->GetNodeType(),
                  Lib3MF::eImplicitNodeType::Addition);
        EXPECT_EQ(nodeIterator->GetCurrent()->GetDisplayName(), "addition 1");

        EXPECT_FALSE(functionIterator->MoveNext());
    }

    // Function with multiple nodes and links between them
    TEST_F(Volumetric, AddFunction_MultipleNodesAndLinksAreWrittenTo3mfFile)
    {
        PImplicitFunction newFunction = model->AddImplicitFunction();
        std::string const displayName = "test";
        newFunction->SetDisplayName(displayName);
        auto const expectedResourceId = newFunction->GetModelResourceID();

        auto functionArgument = newFunction->AddInput(
            "pos", "position", Lib3MF::eImplicitPortType::Vector);

        // Add some nodes

        auto addNode = newFunction->AddAdditionNode(
            "addition_1", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "addition 1", "group_a");
        auto subNode = newFunction->AddSubtractionNode(
            "substraction_1",
            Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "substraction 1", "group_a");
        auto mulNode = newFunction->AddMultiplicationNode(
            "multiplication_1",
            Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "multiplication 1", "group_a");

        // Add some links
        newFunction->AddLink(addNode->GetOutputResult().get(), subNode->GetInputA().get());

        // Alternative way to add links
        mulNode->FindInput("A")->SetReference("addition_1.result");

        auto output =
            newFunction->AddOutput("shape", "signed distance to the surface",
                                   Lib3MF::eImplicitPortType::Scalar);
        
        newFunction->AddLink(subNode->GetOutputResult().get(), output.get());

        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();
        auto theBoundary = volumeData->CreateNewBoundary(newFunction.get());

        // Write to file
        writer3MF->WriteToFile(Volumetric::OutFolder +
                               "AddFunctionWithMultipleNodesAndLinks.3mf");

        // Read from file
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder +
                               "AddFunctionWithMultipleNodesAndLinks.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        // Check the nodes
        EXPECT_TRUE(functionIterator->MoveNext());
        EXPECT_EQ(functionIterator->GetCurrentFunction()->GetModelResourceID(),
                  expectedResourceId);

        // Compare the functions
        helper::compareFunctions(model, newFunction, ioModel,
                                 functionIterator->GetCurrentFunction());
    }

    // Function with constant node
    TEST_F(Volumetric, ImplicitSphere)
    {
        PImplicitFunction newFunction = model->AddImplicitFunction();
        newFunction->SetDisplayName("sphere");
        auto const expectedResourceId = newFunction->GetModelResourceID();

        auto functionArgument = newFunction->AddInput(
            "pos", "position", Lib3MF::eImplicitPortType::Vector);

        // Add some nodes
        auto constMatrixNode = newFunction->AddConstMatNode(
            "matrix_1", "unused example matrix", "group_a");

        // clang-format off
        constMatrixNode->SetMatrix(
          {1.23456, 2.34567, 3.45678, 4.56789,
           5.67890, 6.78901, 7.89012, 8.90123, 
           9.01234, 10.12345, 11.23456, 12.34567, 
           13.45678, 14.56789, 15.67890, 16.78901});
        // clang-format on

        auto constNode = newFunction->AddConstantNode(
            "radius", "radius of the spehere", "group_a");
        constNode->SetConstant(1.23456);

        auto constVecNode = newFunction->AddConstVecNode(
            "vector_1", "translation vector", "group_a");
        constVecNode->SetVector({1.23456, 2.34567, 3.45678});

        auto subNode = newFunction->AddSubtractionNode(
            "translate_1", Lib3MF::eImplicitNodeConfiguration::VectorToVector,
            "Translation", "group_a");


        auto posInput = newFunction->FindInput("pos");
        auto subInputA = subNode->GetInputA();
        newFunction->AddLink(posInput, subInputA);

        auto subInputB = subNode->GetInputB();
        auto constVecOutput = constVecNode->GetOutputVector();
        newFunction->AddLink(constVecOutput, subInputB);

        auto distanceToSpehereNode = newFunction->AddLengthNode(
            "distance_1", "distance to sphere", "group_a");

        newFunction->AddLink(subNode->GetOutputResult().get(),
                             distanceToSpehereNode->GetInputA().get());

        // Substract radius from distance
        auto subNode2 = newFunction->AddSubtractionNode(
            "distance_2", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "distance to sphere", "group_a");

        auto distanceToSphereOutput = distanceToSpehereNode->GetOutputResult();
        auto subNode2InputA = subNode2->GetInputA();
        newFunction->AddLink(distanceToSphereOutput, subNode2InputA);

        auto output =
            newFunction->AddOutput("shape", "signed distance to the surface",
                                   Lib3MF::eImplicitPortType::Scalar);
        output->SetReference("distance_2.result");

        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();
        auto theBoundary = volumeData->CreateNewBoundary(newFunction.get());

        // Write to file
        writer3MF->WriteToFile(Volumetric::OutFolder + "ImplicitSphere.3mf");

        // // Read from file
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder + "ImplicitSphere.3mf");

        // // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        // Check the nodes
        EXPECT_TRUE(functionIterator->MoveNext());
        EXPECT_EQ(functionIterator->GetCurrentFunction()->GetModelResourceID(),
                  expectedResourceId);

        // Compare the functions
        helper::compareFunctions(model, newFunction, ioModel,
                                 functionIterator->GetCurrentFunction());
    }

    TEST_F(Volumetric, ImplicitGyroid)
    {
        PImplicitFunction newFunction = helper::createGyroidFunction(*model);

        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();
        auto theBoundary = volumeData->CreateNewBoundary(newFunction.get());

        // write to file
        writer3MF->WriteToFile(Volumetric::OutFolder + "ImplicitGyroid.3mf");

        // read and compare
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder + "ImplicitGyroid.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        // Check the nodes
        EXPECT_TRUE(functionIterator->MoveNext());

        // Compare the functions
        helper::compareFunctions(model, newFunction, ioModel,
                                 functionIterator->GetCurrentFunction());
    }

    /**
     * @brief Test case for adding an implicit function that references a mesh.
     *
     * @details
     * This test case creates an implicit function that references a mesh and
     writes it to a file.
     * It then reads the file and compares the created function with the
     original one.
     *

     */
    TEST_F(Volumetric, AddImplicitFunction_FunctionReferencingAMesh_SameContent)
    {
        // Create a function
        PImplicitFunction newFunction = model->AddImplicitFunction();
        newFunction->SetDisplayName("shell");

        auto functionArgument = newFunction->AddInput(
            "pos", "position", Lib3MF::eImplicitPortType::Vector);

        auto resourceNode = newFunction->AddResourceIdNode(
            "meshResource", "mesh resource", "group_shell");

        auto mesh = GetMesh();

        resourceNode->SetResource(mesh.get());

        // Create a mesh node
        auto meshNode = newFunction->AddMeshNode("mesh", "mesh", "group_shell");

        newFunction->AddLinkByNames("meshResource.value", "mesh.mesh");

        auto absNode = newFunction->AddAbsNode(
            "abs", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar, "abs",
            "group_shell");

        newFunction->AddLinkByNames("mesh.distance", "abs.A");

        auto constScalarNode = newFunction->AddConstantNode(
            "thickness", "thickness", "group_shell");
        constScalarNode->SetConstant(2.);

        auto subtractionNode = newFunction->AddSubtractionNode(
            "subtraction", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "subtraction", "group_shell");

        newFunction->AddLinkByNames("abs.result", "subtraction.A");
        newFunction->AddLinkByNames("thickness.value", "subtraction.B");

        auto output =
            newFunction->AddOutput("shape", "signed distance to the surface",
                                   Lib3MF::eImplicitPortType::Scalar);

        output->SetReference("subtraction.result");

        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();
        auto theBoundary = volumeData->CreateNewBoundary(newFunction.get());
        theBoundary->SetMinFeatureSize(0.1);
        theBoundary->SetChannelName("shape");

        // write to file
        writer3MF->WriteToFile(Volumetric::OutFolder + "ShellFromMesh.3mf");

        // read and compare
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder + "ShellFromMesh.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        EXPECT_TRUE(functionIterator->MoveNext());

        // Compare the functions
        helper::compareFunctions(model, newFunction, ioModel,
                                 functionIterator->GetCurrentFunction());
    }

    /**
     * @brief Test fixture for the Volumetric class.
     *
     * This fixture tests the `AddImplicitFunction` method of the `Volumetric`
     * class using the Gyroid function and verifies that the resulting content
     * is the same as expected.
     */
    TEST_F(Volumetric, AddImplicitFunction_GyroidFunction_SameContent)
    {
        // Create a gyroid function
        PImplicitFunction gyroidFunction = helper::createGyroidFunction(*model);

        // Create a new implicit function
        PImplicitFunction newFunction = model->AddImplicitFunction();
        newFunction->SetDisplayName("shell");

        // Add an input to the new function
        auto functionArgument = newFunction->AddInput(
            "pos", "position", Lib3MF::eImplicitPortType::Vector);

        // Add a resource node to the new function
        auto resourceNode = newFunction->AddResourceIdNode( "meshResource", "mesh resource", "group_shell");

        // Get the mesh
        auto mesh = GetMesh();

        // Set the resource for the resource node
        resourceNode->SetResource(mesh.get());

        // Create a mesh node
        auto meshNode = newFunction->AddMeshNode("mesh", "mesh", "group_shell");

        auto posInput = newFunction->FindInput("pos");
        auto meshNodeInputPos = meshNode->GetInputPos();
        newFunction->AddLink(posInput, meshNodeInputPos);

        auto resourceNodeOutputValue = resourceNode->GetOutputValue();
        auto meshNodeInputMesh = meshNode->GetInputMesh();
        newFunction->AddLink(resourceNodeOutputValue, meshNodeInputMesh);

        // Add an absolute value node
        auto absNode = newFunction->AddAbsNode(
            "abs", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar, "abs",
            "group_shell");
        
        auto meshNodeOutputDistance = meshNode->GetOutputDistance();
        auto absNodeInputA = absNode->GetInputA();
        newFunction->AddLink(meshNodeOutputDistance, absNodeInputA);

        // Add a constant scalar node
        auto constScalarNode = newFunction->AddConstantNode(
            "thickness", "thickness", "group_shell");

        constScalarNode->SetConstant(2.);

        // Add a subtraction node
        auto subtractionNode = newFunction->AddSubtractionNode(
            "subtraction", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "subtraction", "group_shell");

        auto absNodeOutputResult = absNode->GetOutputResult();
        auto subtractionNodeInputA = subtractionNode->GetInputA();
        newFunction->AddLink(absNodeOutputResult, subtractionNodeInputA);

        auto constScalarNodeOutputValue = constScalarNode->GetOutputValue();
        auto subtractionNodeOutputResult = subtractionNode->GetOutputResult();
        newFunction->AddLink(constScalarNodeOutputValue, subtractionNodeOutputResult);

        // Add an output to the new function
        auto output =
            newFunction->AddOutput("shape", "signed distance to the surface",
                                   Lib3MF::eImplicitPortType::Scalar);

        // Add a function call node for the gyroid function

        auto gyroidNode = newFunction->AddFunctionCallNode(
            "gyroid", "gyroid", "group_gyroid");

        // Add a resource node for the gyroid function


        auto funcitionIdNode = newFunction->AddResourceIdNode(
            "gyroidID", "function resource", "group_gyroid");

        funcitionIdNode->SetResource(gyroidFunction.get());

        auto functionInput = gyroidNode->FindInput("functionID");
        ASSERT_TRUE(functionInput);

        newFunction->AddLinkByNames("gyroidID.value", "gyroid.functionID");

        // Add inputs and outputs for the gyroid function
        auto gyroidPosInput = gyroidNode->AddInput("pos", "position");
        gyroidPosInput->SetType(Lib3MF::eImplicitPortType::Vector);

        auto gyroidShapeOutput = gyroidNode->AddOutput("shape", "signed distance to the surface");
        gyroidShapeOutput->SetType(Lib3MF::eImplicitPortType::Scalar);

        newFunction->AddLink(posInput, gyroidPosInput);       

        // Add a max node
        auto maxNode = newFunction->AddMaxNode(
            "max", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "max - intersection", "group_shell");

        auto maxNodeInputA = maxNode->GetInputA();
        newFunction->AddLink(gyroidShapeOutput, maxNodeInputA);

        auto maxNodeInputB = maxNode->GetInputB();
        newFunction->AddLink(subtractionNodeOutputResult, maxNodeInputB);

        // Set the output reference
        output->SetReference("max.result");

        // Write the model to a file
        writer3MF->WriteToFile(Volumetric::OutFolder +
                               "ShellWithGyroidSubfunction.3mf");

        // Read the model from the file and compare it to the original model
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder +
                               "ShellWithGyroidSubfunction.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 2);

        EXPECT_TRUE(functionIterator->MoveNext());

        // Compare the functions
        helper::compareFunctions(model, gyroidFunction, ioModel,
                                 functionIterator->GetCurrentFunction());
        EXPECT_TRUE(functionIterator->MoveNext());
        helper::compareFunctions(model, newFunction, ioModel,
                                 functionIterator->GetCurrentFunction());
    }

    /**
     * @brief Test case for creating and loading a function from an image3D
     * color.
     *
     * @details This test case creates a model and loads a pyramid. It then
     * creates a new image stack and sets up a function from the image3D. An
     * implicit function is also created and its inputs and outputs are defined.
     * A node is added to call the function from the image3D. The inputs and
     * outputs of the called function are added manually. The color is set and a
     * transformation is applied. The function is then written to a file. The
     * file is read and the function is compared to the original function.
     */
    TEST_F(Volumetric, CreateAndLoad_FunctionFromImage3dColor_SameContent)
    {
        // Create model and load pyramid
        model = wrapper->CreateModel();
        auto reader = model->QueryReader("3mf");
        reader->ReadFromFile(InFolder + "Cube.3mf");

        // Create a new image stack
        auto pImage3D = SetupSheetsFromFile();

        auto funcFromImage3d = model->AddFunctionFromImage3D(pImage3D.get());
        ASSERT_TRUE(funcFromImage3d);
        funcFromImage3d->SetDisplayName("function from image3d");

        funcFromImage3d->SetTileStyles(Lib3MF::eTextureTileStyle::Wrap,
                                       Lib3MF::eTextureTileStyle::Clamp,
                                       Lib3MF::eTextureTileStyle::Mirror);

        // Create a new implicit function
        auto implicitFunction = model->AddImplicitFunction();
        ASSERT_TRUE(implicitFunction);
        implicitFunction->SetDisplayName("implicit function");

        // Add pos as input
        auto posInput = implicitFunction->AddInput(
            "pos", "position", Lib3MF::eImplicitPortType::Vector);
        ASSERT_TRUE(posInput);

        // Add color as output
        auto colorOutput = implicitFunction->AddOutput(
            "color", "color", Lib3MF::eImplicitPortType::Vector);
        ASSERT_TRUE(colorOutput);

        // Call a node to call the function from image3d
        auto functionCallNode = implicitFunction->AddFunctionCallNode(
            "functionCall", "functionCall", "group_functionCall");
        
        auto functionIdNode = implicitFunction->AddResourceIdNode(
            "functionID", "function resource", "group_functionCall");

        functionIdNode->SetResource(funcFromImage3d.get());

        auto functionInput = functionCallNode->GetInputFunctionID();
        ASSERT_TRUE(functionInput);

        EXPECT_EQ(functionInput->GetType(),
                  Lib3MF::eImplicitPortType::ResourceID);

        auto functionIdNodeOutputValue = functionIdNode->GetOutputValue();
        auto functionCallNodeInputFunctionID = functionCallNode->GetInputFunctionID();
        implicitFunction->AddLink(functionIdNodeOutputValue, functionCallNodeInputFunctionID);
        // Currently you have to add the inputs and outputs of the called
        // function manually. We should automate this.

        functionCallNode->AddInput("pos", "position")
            ->SetType(Lib3MF::eImplicitPortType::Vector);

        functionCallNode->AddOutput("color", "signed distance to the surface")
            ->SetType(Lib3MF::eImplicitPortType::Vector);

        implicitFunction->AddLinkByNames("inputs.pos", "functionCall.pos");
        implicitFunction->AddLinkByNames("functionCall.color", "outputs.color");

        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();
        auto theColor = volumeData->CreateNewColor(implicitFunction.get());

        // Set transformation
        auto transformation =
            helper::ComputeTransformFromMeshCoordinatesToUVW(theMesh);
        theColor->SetTransform(transformation);
        theColor->SetChannelName("color");
        theColor->SetMinFeatureSize(0.1);

        // Write to file
        writer3MF = model->QueryWriter("3mf");
        writer3MF->WriteToFile(Volumetric::OutFolder +
                               "FunctionFromImage3D_Color.3mf");

        // Read and compare
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder +
                               "FunctionFromImage3D_Color.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 2);

        EXPECT_TRUE(functionIterator->MoveNext());
        auto functionFromFile = functionIterator->GetCurrentFunction();
        ASSERT_TRUE(functionFromFile);

        PFunctionFromImage3D funcFromFileAsImage3D =
            std::dynamic_pointer_cast<CFunctionFromImage3D>(functionFromFile);

        // Compare the functions
        helper::compareFunctions(model, funcFromImage3d, ioModel,
                                 functionFromFile);
    }

    /**
     * @brief Test case to create and load a function from an image3d and add a
     * boundary to it.
     * @details This test case creates a new image stack and adds a function
     * from the image3d to the model. It then adds a boundary to the volume data
     * and writes the model to a file. The test then reads the file, compares
     * the function and boundary with the original and asserts that they are the
     * same.
     */
    TEST_F(Volumetric, CreateAndLoad_FunctionFromImage3dAddBoundary_SameContent)
    {
        model = wrapper->CreateModel();
        auto reader = model->QueryReader("3mf");
        reader->ReadFromFile(InFolder + "Cube.3mf");

        // Create a new image stack
        auto pImage3D = SetupSheetsFromFile();

        auto funcFromImage3d = model->AddFunctionFromImage3D(pImage3D.get());
        ASSERT_TRUE(funcFromImage3d);
        funcFromImage3d->SetDisplayName("function from image3d");

        auto const funcImg3dId = funcFromImage3d->GetUniqueResourceID();
        funcFromImage3d->SetTileStyles(Lib3MF::eTextureTileStyle::Wrap,
                                       Lib3MF::eTextureTileStyle::Clamp,
                                       Lib3MF::eTextureTileStyle::Mirror);

        // add volume data
        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();

        // Add boundary
        auto boundary = volumeData->CreateNewBoundary(funcFromImage3d.get());
        boundary->SetTransform(
            helper::ComputeTransformFromMeshCoordinatesToUVW(theMesh));
        boundary->SetChannelName("r");
        boundary->SetMeshBBoxOnly(true);

        // Write to file
        writer3MF = model->QueryWriter("3mf");
        writer3MF->WriteToFile(Volumetric::OutFolder + "Boundary.3mf");

        // Read and compare
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder + "Boundary.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        EXPECT_TRUE(functionIterator->MoveNext());
        auto functionFromFile = functionIterator->GetCurrentFunction();
        ASSERT_TRUE(functionFromFile);

        PFunctionFromImage3D funcFromFileAsImage3D =
            std::dynamic_pointer_cast<CFunctionFromImage3D>(functionFromFile);

        // Compare the functions
        helper::compareFunctions(model, funcFromImage3d, ioModel,
                                 functionFromFile);

        // Check the boundary
        auto boundaryFromFile = volumeData->GetBoundary();
        ASSERT_TRUE(boundaryFromFile);
        EXPECT_EQ(boundaryFromFile->GetFunctionResourceID(), funcImg3dId);
        helper::CompareTransforms(boundary->GetTransform(),
                                  boundaryFromFile->GetTransform());
        EXPECT_EQ(boundary->GetChannelName(),
                  boundaryFromFile->GetChannelName());
        EXPECT_EQ(boundary->GetMeshBBoxOnly(),
                  boundaryFromFile->GetMeshBBoxOnly());
    }

    /**
     * @brief Test case for creating and loading a function from an image3d and
     * adding a property with the same content.
     *
     * @details This test case creates a new model, reads a 3mf file into it,
     * creates a new image stack, and adds a function from the image3d to the
     * model. It then adds volume data to the mesh, adds a property from the
     * function to the volume data, and writes the model to a file. The test
     * then reads the file and compares the function and property to the
     * original ones.
     *
     * @note This test requires the Cube.3mf file to be present in the InFolder
     * directory and for the OutFolder directory to exist.
     */
    TEST_F(Volumetric, CreateAndLoad_FunctionFromImage3dAddProperty_SameContent)
    {
        model = wrapper->CreateModel();
        auto reader = model->QueryReader("3mf");
        reader->ReadFromFile(InFolder + "Cube.3mf");

        // Create a new image stack
        auto pImage3D = SetupSheetsFromFile();

        auto funcFromImage3d = model->AddFunctionFromImage3D(pImage3D.get());
        ASSERT_TRUE(funcFromImage3d);
        funcFromImage3d->SetDisplayName("function from image3d");

        auto const funcImg3dId = funcFromImage3d->GetUniqueResourceID();
        funcFromImage3d->SetTileStyles(Lib3MF::eTextureTileStyle::Wrap,
                                       Lib3MF::eTextureTileStyle::Clamp,
                                       Lib3MF::eTextureTileStyle::Mirror);

        // add volume data
        auto theMesh = GetMesh();
        auto volumeData = theMesh->VolumeData();

        // Add property
        auto property =
            volumeData->AddPropertyFromFunction("Temp", funcFromImage3d.get());
        property->SetTransform(
            helper::ComputeTransformFromMeshCoordinatesToUVW(theMesh));
        std::string const ChannelName = "g";
        property->SetChannelName(ChannelName);

        // Write to file
        writer3MF = model->QueryWriter("3mf");
        writer3MF->WriteToFile(Volumetric::OutFolder + "Property.3mf");

        // Read and compare
        PModel ioModel = wrapper->CreateModel();
        PReader ioReader = ioModel->QueryReader("3mf");
        ioReader->ReadFromFile(Volumetric::OutFolder + "Property.3mf");

        // Check the function
        auto functionIterator = ioModel->GetFunctions();
        ASSERT_EQ(functionIterator->Count(), 1);

        EXPECT_TRUE(functionIterator->MoveNext());
        auto functionFromFile = functionIterator->GetCurrentFunction();
        ASSERT_TRUE(functionFromFile);

        PFunctionFromImage3D funcFromFileAsImage3D =
            std::dynamic_pointer_cast<CFunctionFromImage3D>(functionFromFile);

        // Compare the functions
        helper::compareFunctions(model, funcFromImage3d, ioModel,
                                 functionFromFile);

        // Check the property
        ASSERT_EQ(volumeData->GetPropertyCount(), 1);
        auto propertyFromFile = volumeData->GetProperty(0);
        ASSERT_TRUE(propertyFromFile);
        EXPECT_EQ(propertyFromFile->GetFunctionResourceID(), funcImg3dId);
        helper::CompareTransforms(property->GetTransform(),
                                  propertyFromFile->GetTransform());
        EXPECT_EQ(property->GetChannelName(), ChannelName);
        EXPECT_EQ(property->GetName(), propertyFromFile->GetName());
    }

    /**
     * @brief Test case to verify that the MergeFromModel function merges a
     * function from a source model into an empty target model.
     *
     * @details This test case creates an empty target model and a source model
     * with a gyroid function. It then merges the source model into the target
     * model and verifies that the gyroid function is present in the target
     * model.
     */
    TEST_F(Volumetric, MergeModel_FunctionIntoEmptyModel_ResourceIdsAreTheSame)
    {
        auto const targetModel = wrapper->CreateModel();
        auto const sourceModel = wrapper->CreateModel();

        auto const gyroidFunction = helper::createGyroidFunction(*sourceModel);

        EXPECT_EQ(targetModel->GetFunctions()->Count(), 0u);
        EXPECT_EQ(sourceModel->GetFunctions()->Count(), 1u);

        targetModel->MergeFromModel(sourceModel.get());

        auto targetFunctionsIter = targetModel->GetFunctions();
        EXPECT_EQ(targetFunctionsIter->Count(), 1u);

        EXPECT_TRUE(targetFunctionsIter->MoveNext());
        auto const targetFunction = targetFunctionsIter->GetCurrentFunction();
        ASSERT_TRUE(targetFunction);
        helper::compareFunctions(sourceModel, gyroidFunction, targetModel,
                                 targetFunction);
    }

    TEST_F(
        Volumetric,
        MergeModel_FunctionIntoModelContainingAFunction_ResourceIdsAreUpdated)
    {
        auto const targetModel = wrapper->CreateModel();
        auto const sourceModel = wrapper->CreateModel();

        auto const gyroidFunction = helper::createGyroidFunction(*sourceModel);

        auto const targetGyroidFunction =
            helper::createGyroidFunction(*targetModel);

        targetModel->MergeFromModel(sourceModel.get());

        auto targetFunctionsIter = targetModel->GetFunctions();
        EXPECT_EQ(targetFunctionsIter->Count(), 2u);

        EXPECT_TRUE(targetFunctionsIter->MoveNext());
        auto const targetFunction = targetFunctionsIter->GetCurrentFunction();
        ASSERT_TRUE(targetFunction);
        EXPECT_EQ(targetFunction->GetModelResourceID(), 1u);

        EXPECT_TRUE(targetFunctionsIter->MoveNext());
        auto const mergedFunction = targetFunctionsIter->GetCurrentFunction();
        ASSERT_TRUE(mergedFunction);
        EXPECT_EQ(mergedFunction->GetModelResourceID(), 2u);

        // Save the target model to a file
        writer3MF = targetModel->QueryWriter("3mf");
        writer3MF->WriteToFile(Volumetric::OutFolder + "TwoFunctions.3mf");
    }

    TEST_F(Volumetric, AddLink_InvalidTypes_ThrowsException)
    {
        auto const function = model->AddImplicitFunction();

        auto const constVector = function->AddConstVecNode(
            "constVector", "constVector", "group_constVector");

        auto const scalarAdd = function->AddAdditionNode(
            "scalarAdd", Lib3MF::eImplicitNodeConfiguration::ScalarToScalar,
            "scalarAdd", "group_scalarAdd");

        auto const inputA = scalarAdd->GetInputA();
        auto const vectorOutput = constVector->GetOutputVector();
        EXPECT_THROW(function->AddLink(inputA, vectorOutput),
                     ELib3MFException);
    }

    /**
     * @brief Test case for sorting nodes topologically. The function creates a cyclic graph with three nodes and sets up circular 
     * dependencies between them. The test expects the function to throw an exception when trying to sort the nodes topologically.
     *
     * Graph structure:
     *
     *          +--------+
     *          |        |
     *          v        |
     *      +-------+    |
     *      | add1  |    |
     *      +-------+    |
     *          ^        |
     *          |        |
     *    +-----------+  |
     *    | constVec1 |  |
     *    +-----------+  |
     *          |        |
     *          v        |
     *      +-------+    |
     *      | add2  |    |
     *      +-------+    |
     *          ^        |
     *          |        |
     *          +--------+
     *
     */
    TEST_F(Volumetric, SortNodesTopologically_CyclicGraph_Throws)
    {
        auto const function = model->AddImplicitFunction();
        
        function->AddInput("pos", "position", Lib3MF::eImplicitPortType::Vector);
        // Add nodes with circular dependencies
        auto const constVec1 = function->AddConstVecNode("constVec1", "constVec1", "group1");
        auto const add1 = function->AddAdditionNode("add1", Lib3MF::eImplicitNodeConfiguration::VectorToVector, "add1", "group1");
        auto const add2 = function->AddAdditionNode("add2", Lib3MF::eImplicitNodeConfiguration::VectorToVector, "add2", "group1");

        // Set up circular dependencies
        auto const vectorOutput = constVec1->GetOutputVector();
        auto const inputAdd1A = add1->GetInputA();
        auto const inputAdd1B = add1->GetInputB();

        auto const inputAdd2A = add2->GetInputA();
        auto const inputAdd2B = add2->GetInputB();

        auto const outputAdd1 = add1->GetOutputResult();
        auto const outputAdd2 = add2->GetOutputResult();
        function->AddLink(vectorOutput, inputAdd1A);
        function->AddLink(outputAdd2, inputAdd1B);
        function->AddLink(outputAdd1, inputAdd1A);
        function->AddLink(vectorOutput, inputAdd2A);
        function->AddLink(outputAdd1, inputAdd2B);
        EXPECT_THROW(function->SortNodesTopologically(), ELib3MFException);
    }
}  // namespace Lib3MF
