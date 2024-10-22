/*++

Copyright (C) 2024 3MF Consortium (Original Author)

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

This file has been generated by the Automatic Component Toolkit (ACT) version 1.8.0-develop.

Abstract: This is an autogenerated plain C Header file with basic types in
order to allow an easy use of the 3MF Library

Interface version: 2.4.0

*/

#ifndef __LIB3MF_TYPES_HEADER
#define __LIB3MF_TYPES_HEADER

#include <stdbool.h>

/*************************************************************************************************************************
 Scalar types definition
**************************************************************************************************************************/

#ifdef LIB3MF_USELEGACYINTEGERTYPES

typedef unsigned char Lib3MF_uint8;
typedef unsigned short Lib3MF_uint16 ;
typedef unsigned int Lib3MF_uint32;
typedef unsigned long long Lib3MF_uint64;
typedef char Lib3MF_int8;
typedef short Lib3MF_int16;
typedef int Lib3MF_int32;
typedef long long Lib3MF_int64;

#else // LIB3MF_USELEGACYINTEGERTYPES

#include <stdint.h>

typedef uint8_t Lib3MF_uint8;
typedef uint16_t Lib3MF_uint16;
typedef uint32_t Lib3MF_uint32;
typedef uint64_t Lib3MF_uint64;
typedef int8_t Lib3MF_int8;
typedef int16_t Lib3MF_int16;
typedef int32_t Lib3MF_int32;
typedef int64_t Lib3MF_int64 ;

#endif // LIB3MF_USELEGACYINTEGERTYPES

typedef float Lib3MF_single;
typedef double Lib3MF_double;

/*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************/

typedef Lib3MF_int32 Lib3MFResult;
typedef void * Lib3MFHandle;
typedef void * Lib3MF_pvoid;

/*************************************************************************************************************************
 Version for Lib3MF
**************************************************************************************************************************/

#define LIB3MF_VERSION_MAJOR 2
#define LIB3MF_VERSION_MINOR 4
#define LIB3MF_VERSION_MICRO 0
#define LIB3MF_VERSION_PRERELEASEINFO ""
#define LIB3MF_VERSION_BUILDINFO ""

/*************************************************************************************************************************
 Error constants for Lib3MF
**************************************************************************************************************************/

#define LIB3MF_SUCCESS 0
#define LIB3MF_ERROR_NOTIMPLEMENTED 1 /** functionality not implemented */
#define LIB3MF_ERROR_INVALIDPARAM 2 /** an invalid parameter was passed */
#define LIB3MF_ERROR_INVALIDCAST 3 /** a type cast failed */
#define LIB3MF_ERROR_BUFFERTOOSMALL 4 /** a provided buffer is too small */
#define LIB3MF_ERROR_GENERICEXCEPTION 5 /** a generic exception occurred */
#define LIB3MF_ERROR_COULDNOTLOADLIBRARY 6 /** the library could not be loaded */
#define LIB3MF_ERROR_COULDNOTFINDLIBRARYEXPORT 7 /** a required exported symbol could not be found in the library */
#define LIB3MF_ERROR_INCOMPATIBLEBINARYVERSION 8 /** the version of the binary interface does not match the bindings interface */
#define LIB3MF_ERROR_CALCULATIONABORTED 10 /** a calculation has been aborted */
#define LIB3MF_ERROR_SHOULDNOTBECALLED 11 /** functionality should not be called */
#define LIB3MF_ERROR_READERCLASSUNKNOWN 100 /** the queried reader class is unknown */
#define LIB3MF_ERROR_WRITERCLASSUNKNOWN 101 /** the queried writer class is unknown */
#define LIB3MF_ERROR_ITERATORINVALIDINDEX 102 /** the current index of an iterator is invalid */
#define LIB3MF_ERROR_INVALIDMODELRESOURCE 103 /** no Model Resource has been given */
#define LIB3MF_ERROR_RESOURCENOTFOUND 104 /** Resource not found */
#define LIB3MF_ERROR_INVALIDMODEL 105 /** A model is invalid */
#define LIB3MF_ERROR_INVALIDOBJECT 106 /** An object is invalid */
#define LIB3MF_ERROR_INVALIDMESHOBJECT 107 /** A mesh object is invalid */
#define LIB3MF_ERROR_INVALIDCOMPONENTSOBJECT 108 /** A components object is invalid */
#define LIB3MF_ERROR_INVALIDCOMPONENT 109 /** A component is invalid */
#define LIB3MF_ERROR_INVALIDBUILDITEM 110 /** A build item is invalid */
#define LIB3MF_ERROR_INVALIDBASEMATERIALGROUP 111 /** A basematerialgroup is invalid */
#define LIB3MF_ERROR_INVALIDSLICESTACKRESOURCE 112 /** A slicestack resource is invalid */
#define LIB3MF_ERROR_INVALIDTEXTURERESOURCE 113 /** A texture resource is invalid */
#define LIB3MF_ERROR_INVALIDCOLORGROUP 114 /** A color group resource is invalid */
#define LIB3MF_ERROR_INVALIDTEXTURE2DGROUP 115 /** A texture2d group resource is invalid */
#define LIB3MF_ERROR_INVALIDCOMPOSITEMATERIALS 116 /** A composite materials resource is invalid */
#define LIB3MF_ERROR_INVALIDMULTIPROPERTYGROUP 117 /** A MultiPropertyGroup resource is invalid */
#define LIB3MF_ERROR_INVALIDRESOURCEINDEX 120 /** A resource index is invalid */
#define LIB3MF_ERROR_ATTACHMENTNOTFOUND 121 /** Attachment not found */
#define LIB3MF_ERROR_FORBIDDENCYCLICREFERENCE 130 /** A component references one of its ancestors */
#define LIB3MF_ERROR_INVALIDATTACHMENTSTREAM 131 /** An attachment stream is invalid */
#define LIB3MF_ERROR_INVALIDPROPERTYCOUNT 132 /** Invalid property count. */
#define LIB3MF_ERROR_UNKOWNPROGRESSIDENTIFIER 140 /** A progress identifier is unknown */
#define LIB3MF_ERROR_ELEMENTCOUNTEXCEEDSLIMIT 141 /** An element buffer exceeds its spec limit */
#define LIB3MF_ERROR_INVALIDRESOURCE 142 /** A resource is invalid */
#define LIB3MF_ERROR_INVALIDLEVELSET 143 /** A level set is invalid */
#define LIB3MF_ERROR_BEAMLATTICE_INVALID_OBJECTTYPE 2000 /** This object type is not valid for beamlattices */
#define LIB3MF_ERROR_INVALIDKEYSTORE 3000 /** The keystore object is invalid */
#define LIB3MF_ERROR_INVALIDKEYSTORECONSUMER 3001 /** The consumer keystore object is invalid */
#define LIB3MF_ERROR_KEYSTORECONSUMERNOTFOUND 3002 /** A consumer has not been found */
#define LIB3MF_ERROR_KEYSTORERESOURCEDATANOTFOUND 3003 /** A resource data has not been found */
#define LIB3MF_ERROR_SECURECONTEXTNOTREGISTERED 3004 /** A Key or Conentent encryption callback has not been registered */
#define LIB3MF_ERROR_INVALIDKEYSIZE 3005 /** The key size is invalid */
#define LIB3MF_ERROR_INCOMPATIBLEPORTTYPES 4000 /** Link could not be added, the port types are incompatible */
#define LIB3MF_ERROR_GRAPHISCYCLIC 4001 /** The functin graph is cyclic. Only dircected graphs are valid and can be topological sorted. */
#define LIB3MF_ERROR_INPUTNOTSET 4002 /** The input of a node is not set. */
#define LIB3MF_ERROR_INVALIDNODECONFIGURATION 4003 /** The selected node configuration is not supported */

/*************************************************************************************************************************
 Error strings for Lib3MF
**************************************************************************************************************************/

inline const char * LIB3MF_GETERRORSTRING (Lib3MFResult nErrorCode) {
  switch (nErrorCode) {
    case LIB3MF_SUCCESS: return "no error";
    case LIB3MF_ERROR_NOTIMPLEMENTED: return "functionality not implemented";
    case LIB3MF_ERROR_INVALIDPARAM: return "an invalid parameter was passed";
    case LIB3MF_ERROR_INVALIDCAST: return "a type cast failed";
    case LIB3MF_ERROR_BUFFERTOOSMALL: return "a provided buffer is too small";
    case LIB3MF_ERROR_GENERICEXCEPTION: return "a generic exception occurred";
    case LIB3MF_ERROR_COULDNOTLOADLIBRARY: return "the library could not be loaded";
    case LIB3MF_ERROR_COULDNOTFINDLIBRARYEXPORT: return "a required exported symbol could not be found in the library";
    case LIB3MF_ERROR_INCOMPATIBLEBINARYVERSION: return "the version of the binary interface does not match the bindings interface";
    case LIB3MF_ERROR_CALCULATIONABORTED: return "a calculation has been aborted";
    case LIB3MF_ERROR_SHOULDNOTBECALLED: return "functionality should not be called";
    case LIB3MF_ERROR_READERCLASSUNKNOWN: return "the queried reader class is unknown";
    case LIB3MF_ERROR_WRITERCLASSUNKNOWN: return "the queried writer class is unknown";
    case LIB3MF_ERROR_ITERATORINVALIDINDEX: return "the current index of an iterator is invalid";
    case LIB3MF_ERROR_INVALIDMODELRESOURCE: return "no Model Resource has been given";
    case LIB3MF_ERROR_RESOURCENOTFOUND: return "Resource not found";
    case LIB3MF_ERROR_INVALIDMODEL: return "A model is invalid";
    case LIB3MF_ERROR_INVALIDOBJECT: return "An object is invalid";
    case LIB3MF_ERROR_INVALIDMESHOBJECT: return "A mesh object is invalid";
    case LIB3MF_ERROR_INVALIDCOMPONENTSOBJECT: return "A components object is invalid";
    case LIB3MF_ERROR_INVALIDCOMPONENT: return "A component is invalid";
    case LIB3MF_ERROR_INVALIDBUILDITEM: return "A build item is invalid";
    case LIB3MF_ERROR_INVALIDBASEMATERIALGROUP: return "A basematerialgroup is invalid";
    case LIB3MF_ERROR_INVALIDSLICESTACKRESOURCE: return "A slicestack resource is invalid";
    case LIB3MF_ERROR_INVALIDTEXTURERESOURCE: return "A texture resource is invalid";
    case LIB3MF_ERROR_INVALIDCOLORGROUP: return "A color group resource is invalid";
    case LIB3MF_ERROR_INVALIDTEXTURE2DGROUP: return "A texture2d group resource is invalid";
    case LIB3MF_ERROR_INVALIDCOMPOSITEMATERIALS: return "A composite materials resource is invalid";
    case LIB3MF_ERROR_INVALIDMULTIPROPERTYGROUP: return "A MultiPropertyGroup resource is invalid";
    case LIB3MF_ERROR_INVALIDRESOURCEINDEX: return "A resource index is invalid";
    case LIB3MF_ERROR_ATTACHMENTNOTFOUND: return "Attachment not found";
    case LIB3MF_ERROR_FORBIDDENCYCLICREFERENCE: return "A component references one of its ancestors";
    case LIB3MF_ERROR_INVALIDATTACHMENTSTREAM: return "An attachment stream is invalid";
    case LIB3MF_ERROR_INVALIDPROPERTYCOUNT: return "Invalid property count.";
    case LIB3MF_ERROR_UNKOWNPROGRESSIDENTIFIER: return "A progress identifier is unknown";
    case LIB3MF_ERROR_ELEMENTCOUNTEXCEEDSLIMIT: return "An element buffer exceeds its spec limit";
    case LIB3MF_ERROR_INVALIDRESOURCE: return "A resource is invalid";
    case LIB3MF_ERROR_INVALIDLEVELSET: return "A level set is invalid";
    case LIB3MF_ERROR_BEAMLATTICE_INVALID_OBJECTTYPE: return "This object type is not valid for beamlattices";
    case LIB3MF_ERROR_INVALIDKEYSTORE: return "The keystore object is invalid";
    case LIB3MF_ERROR_INVALIDKEYSTORECONSUMER: return "The consumer keystore object is invalid";
    case LIB3MF_ERROR_KEYSTORECONSUMERNOTFOUND: return "A consumer has not been found";
    case LIB3MF_ERROR_KEYSTORERESOURCEDATANOTFOUND: return "A resource data has not been found";
    case LIB3MF_ERROR_SECURECONTEXTNOTREGISTERED: return "A Key or Conentent encryption callback has not been registered";
    case LIB3MF_ERROR_INVALIDKEYSIZE: return "The key size is invalid";
    case LIB3MF_ERROR_INCOMPATIBLEPORTTYPES: return "Link could not be added, the port types are incompatible";
    case LIB3MF_ERROR_GRAPHISCYCLIC: return "The functin graph is cyclic. Only dircected graphs are valid and can be topological sorted.";
    case LIB3MF_ERROR_INPUTNOTSET: return "The input of a node is not set.";
    case LIB3MF_ERROR_INVALIDNODECONFIGURATION: return "The selected node configuration is not supported";
    default: return "unknown error";
  }
}

/*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************/

typedef Lib3MFHandle Lib3MF_Base;
typedef Lib3MFHandle Lib3MF_Writer;
typedef Lib3MFHandle Lib3MF_Reader;
typedef Lib3MFHandle Lib3MF_PackagePart;
typedef Lib3MFHandle Lib3MF_Resource;
typedef Lib3MFHandle Lib3MF_ResourceIterator;
typedef Lib3MFHandle Lib3MF_SliceStackIterator;
typedef Lib3MFHandle Lib3MF_ObjectIterator;
typedef Lib3MFHandle Lib3MF_MeshObjectIterator;
typedef Lib3MFHandle Lib3MF_ComponentsObjectIterator;
typedef Lib3MFHandle Lib3MF_Texture2DIterator;
typedef Lib3MFHandle Lib3MF_BaseMaterialGroupIterator;
typedef Lib3MFHandle Lib3MF_ColorGroupIterator;
typedef Lib3MFHandle Lib3MF_Texture2DGroupIterator;
typedef Lib3MFHandle Lib3MF_CompositeMaterialsIterator;
typedef Lib3MFHandle Lib3MF_MultiPropertyGroupIterator;
typedef Lib3MFHandle Lib3MF_Image3DIterator;
typedef Lib3MFHandle Lib3MF_FunctionIterator;
typedef Lib3MFHandle Lib3MF_LevelSetIterator;
typedef Lib3MFHandle Lib3MF_MetaData;
typedef Lib3MFHandle Lib3MF_MetaDataGroup;
typedef Lib3MFHandle Lib3MF_Object;
typedef Lib3MFHandle Lib3MF_MeshObject;
typedef Lib3MFHandle Lib3MF_LevelSet;
typedef Lib3MFHandle Lib3MF_BeamLattice;
typedef Lib3MFHandle Lib3MF_FunctionReference;
typedef Lib3MFHandle Lib3MF_VolumeDataColor;
typedef Lib3MFHandle Lib3MF_MaterialMapping;
typedef Lib3MFHandle Lib3MF_VolumeDataComposite;
typedef Lib3MFHandle Lib3MF_VolumeDataProperty;
typedef Lib3MFHandle Lib3MF_VolumeData;
typedef Lib3MFHandle Lib3MF_Component;
typedef Lib3MFHandle Lib3MF_ComponentsObject;
typedef Lib3MFHandle Lib3MF_BeamSet;
typedef Lib3MFHandle Lib3MF_BaseMaterialGroup;
typedef Lib3MFHandle Lib3MF_ColorGroup;
typedef Lib3MFHandle Lib3MF_Texture2DGroup;
typedef Lib3MFHandle Lib3MF_CompositeMaterials;
typedef Lib3MFHandle Lib3MF_MultiPropertyGroup;
typedef Lib3MFHandle Lib3MF_Image3D;
typedef Lib3MFHandle Lib3MF_ImageStack;
typedef Lib3MFHandle Lib3MF_Attachment;
typedef Lib3MFHandle Lib3MF_Texture2D;
typedef Lib3MFHandle Lib3MF_ImplicitPort;
typedef Lib3MFHandle Lib3MF_Iterator;
typedef Lib3MFHandle Lib3MF_ImplicitPortIterator;
typedef Lib3MFHandle Lib3MF_ImplicitNode;
typedef Lib3MFHandle Lib3MF_OneInputNode;
typedef Lib3MFHandle Lib3MF_SinNode;
typedef Lib3MFHandle Lib3MF_CosNode;
typedef Lib3MFHandle Lib3MF_TanNode;
typedef Lib3MFHandle Lib3MF_ArcSinNode;
typedef Lib3MFHandle Lib3MF_ArcCosNode;
typedef Lib3MFHandle Lib3MF_ArcTanNode;
typedef Lib3MFHandle Lib3MF_SinhNode;
typedef Lib3MFHandle Lib3MF_CoshNode;
typedef Lib3MFHandle Lib3MF_TanhNode;
typedef Lib3MFHandle Lib3MF_RoundNode;
typedef Lib3MFHandle Lib3MF_CeilNode;
typedef Lib3MFHandle Lib3MF_FloorNode;
typedef Lib3MFHandle Lib3MF_SignNode;
typedef Lib3MFHandle Lib3MF_FractNode;
typedef Lib3MFHandle Lib3MF_AbsNode;
typedef Lib3MFHandle Lib3MF_ExpNode;
typedef Lib3MFHandle Lib3MF_LogNode;
typedef Lib3MFHandle Lib3MF_Log2Node;
typedef Lib3MFHandle Lib3MF_Log10Node;
typedef Lib3MFHandle Lib3MF_LengthNode;
typedef Lib3MFHandle Lib3MF_TransposeNode;
typedef Lib3MFHandle Lib3MF_InverseNode;
typedef Lib3MFHandle Lib3MF_SqrtNode;
typedef Lib3MFHandle Lib3MF_ResourceIdNode;
typedef Lib3MFHandle Lib3MF_TwoInputNode;
typedef Lib3MFHandle Lib3MF_AdditionNode;
typedef Lib3MFHandle Lib3MF_SubtractionNode;
typedef Lib3MFHandle Lib3MF_MultiplicationNode;
typedef Lib3MFHandle Lib3MF_DivisionNode;
typedef Lib3MFHandle Lib3MF_DotNode;
typedef Lib3MFHandle Lib3MF_CrossNode;
typedef Lib3MFHandle Lib3MF_ArcTan2Node;
typedef Lib3MFHandle Lib3MF_MatVecMultiplicationNode;
typedef Lib3MFHandle Lib3MF_MinNode;
typedef Lib3MFHandle Lib3MF_MaxNode;
typedef Lib3MFHandle Lib3MF_FmodNode;
typedef Lib3MFHandle Lib3MF_ModNode;
typedef Lib3MFHandle Lib3MF_PowNode;
typedef Lib3MFHandle Lib3MF_SelectNode;
typedef Lib3MFHandle Lib3MF_ClampNode;
typedef Lib3MFHandle Lib3MF_ComposeVectorNode;
typedef Lib3MFHandle Lib3MF_VectorFromScalarNode;
typedef Lib3MFHandle Lib3MF_DecomposeVectorNode;
typedef Lib3MFHandle Lib3MF_ComposeMatrixNode;
typedef Lib3MFHandle Lib3MF_MatrixFromRowsNode;
typedef Lib3MFHandle Lib3MF_MatrixFromColumnsNode;
typedef Lib3MFHandle Lib3MF_ConstantNode;
typedef Lib3MFHandle Lib3MF_ConstVecNode;
typedef Lib3MFHandle Lib3MF_ConstMatNode;
typedef Lib3MFHandle Lib3MF_MeshNode;
typedef Lib3MFHandle Lib3MF_UnsignedMeshNode;
typedef Lib3MFHandle Lib3MF_FunctionCallNode;
typedef Lib3MFHandle Lib3MF_NodeIterator;
typedef Lib3MFHandle Lib3MF_Function;
typedef Lib3MFHandle Lib3MF_ImplicitFunction;
typedef Lib3MFHandle Lib3MF_FunctionFromImage3D;
typedef Lib3MFHandle Lib3MF_BuildItem;
typedef Lib3MFHandle Lib3MF_BuildItemIterator;
typedef Lib3MFHandle Lib3MF_Slice;
typedef Lib3MFHandle Lib3MF_SliceStack;
typedef Lib3MFHandle Lib3MF_Consumer;
typedef Lib3MFHandle Lib3MF_AccessRight;
typedef Lib3MFHandle Lib3MF_ContentEncryptionParams;
typedef Lib3MFHandle Lib3MF_ResourceData;
typedef Lib3MFHandle Lib3MF_ResourceDataGroup;
typedef Lib3MFHandle Lib3MF_KeyStore;
typedef Lib3MFHandle Lib3MF_Model;

/*************************************************************************************************************************
 Declaration of enums
**************************************************************************************************************************/

typedef enum eLib3MFPropertyType {
  ePropertyTypeNoPropertyType = 0,
  ePropertyTypeBaseMaterial = 1,
  ePropertyTypeTexCoord = 2,
  ePropertyTypeColors = 3,
  ePropertyTypeComposite = 4,
  ePropertyTypeMulti = 5
} eLib3MFPropertyType;

typedef enum eLib3MFSlicesMeshResolution {
  eSlicesMeshResolutionFullres = 0,
  eSlicesMeshResolutionLowres = 1
} eLib3MFSlicesMeshResolution;

typedef enum eLib3MFModelUnit {
  eModelUnitMicroMeter = 0,
  eModelUnitMilliMeter = 1,
  eModelUnitCentiMeter = 2,
  eModelUnitInch = 3,
  eModelUnitFoot = 4,
  eModelUnitMeter = 5
} eLib3MFModelUnit;

typedef enum eLib3MFObjectType {
  eObjectTypeOther = 0,
  eObjectTypeModel = 1,
  eObjectTypeSupport = 2,
  eObjectTypeSolidSupport = 3
} eLib3MFObjectType;

typedef enum eLib3MFTextureType {
  eTextureTypeUnknown = 0,
  eTextureTypePNG = 1,
  eTextureTypeJPEG = 2
} eLib3MFTextureType;

typedef enum eLib3MFTextureTileStyle {
  eTextureTileStyleWrap = 0,
  eTextureTileStyleMirror = 1,
  eTextureTileStyleClamp = 2,
  eTextureTileStyleNoTileStyle = 3
} eLib3MFTextureTileStyle;

typedef enum eLib3MFTextureFilter {
  eTextureFilterAuto = 0,
  eTextureFilterLinear = 1,
  eTextureFilterNearest = 2
} eLib3MFTextureFilter;

typedef enum eLib3MFBeamLatticeCapMode {
  eBeamLatticeCapModeSphere = 0,
  eBeamLatticeCapModeHemiSphere = 1,
  eBeamLatticeCapModeButt = 2
} eLib3MFBeamLatticeCapMode;

typedef enum eLib3MFBeamLatticeClipMode {
  eBeamLatticeClipModeNoClipMode = 0,
  eBeamLatticeClipModeInside = 1,
  eBeamLatticeClipModeOutside = 2
} eLib3MFBeamLatticeClipMode;

typedef enum eLib3MFBeamLatticeBallMode {
  eBeamLatticeBallModeBeamLatticeBallModeNone = 0,
  eBeamLatticeBallModeMixed = 1,
  eBeamLatticeBallModeAll = 2
} eLib3MFBeamLatticeBallMode;

typedef enum eLib3MFProgressIdentifier {
  eProgressIdentifierQUERYCANCELED = 0,
  eProgressIdentifierDONE = 1,
  eProgressIdentifierCLEANUP = 2,
  eProgressIdentifierREADSTREAM = 3,
  eProgressIdentifierEXTRACTOPCPACKAGE = 4,
  eProgressIdentifierREADNONROOTMODELS = 5,
  eProgressIdentifierREADROOTMODEL = 6,
  eProgressIdentifierREADRESOURCES = 7,
  eProgressIdentifierREADMESH = 8,
  eProgressIdentifierREADSLICES = 9,
  eProgressIdentifierREADBUILD = 10,
  eProgressIdentifierREADCUSTOMATTACHMENT = 11,
  eProgressIdentifierREADTEXTURETACHMENTS = 12,
  eProgressIdentifierCREATEOPCPACKAGE = 13,
  eProgressIdentifierWRITEMODELSTOSTREAM = 14,
  eProgressIdentifierWRITEROOTMODEL = 15,
  eProgressIdentifierWRITENONROOTMODELS = 16,
  eProgressIdentifierWRITEATTACHMENTS = 17,
  eProgressIdentifierWRITECONTENTTYPES = 18,
  eProgressIdentifierWRITENOBJECTS = 19,
  eProgressIdentifierWRITENODES = 20,
  eProgressIdentifierWRITETRIANGLES = 21,
  eProgressIdentifierWRITESLICES = 22,
  eProgressIdentifierWRITEKEYSTORE = 23
} eLib3MFProgressIdentifier;

typedef enum eLib3MFBlendMethod {
  eBlendMethodNoBlendMethod = 0,
  eBlendMethodMix = 1,
  eBlendMethodMultiply = 2
} eLib3MFBlendMethod;

typedef enum eLib3MFChannelName {
  eChannelNameRed = 0,
  eChannelNameGreen = 1,
  eChannelNameBlue = 2,
  eChannelNameAlpha = 3
} eLib3MFChannelName;

typedef enum eLib3MFCompositionMethod {
  eCompositionMethodWeightedSum = 0,
  eCompositionMethodMultiply = 1,
  eCompositionMethodMin = 2,
  eCompositionMethodMax = 3,
  eCompositionMethodMask = 4
} eLib3MFCompositionMethod;

typedef enum eLib3MFCompositionSpace {
  eCompositionSpaceRaw = 0,
  eCompositionSpaceLinearColor = 1
} eLib3MFCompositionSpace;

/**
* enum eLib3MFImplicitNodeType - The type of the node
*/
typedef enum eLib3MFImplicitNodeType {
  eImplicitNodeTypeAddition = 1, /** Adds to values (scalar or vector) */
  eImplicitNodeTypeSubtraction = 2, /** Subtracts two values (scalar or vector) */
  eImplicitNodeTypeMultiplication = 3, /** Multiplies two values (scalar or vector) */
  eImplicitNodeTypeDivision = 4, /** Divides two values (scalar or vector) */
  eImplicitNodeTypeConstant = 5, /** A constant scalar value */
  eImplicitNodeTypeConstVec = 6, /** A constant vector value */
  eImplicitNodeTypeConstMat = 7, /** A constant matrix value */
  eImplicitNodeTypeComposeVector = 8, /** Creates a vector from three scalar values */
  eImplicitNodeTypeDecomposeVector = 9, /** Decomposes a vector into three scalar values */
  eImplicitNodeTypeComposeMatrix = 10, /** Creates a matrix from nine scalar values */
  eImplicitNodeTypeMatrixFromColumns = 11, /** Creates a matrix from three column vector values */
  eImplicitNodeTypeMatrixFromRows = 12, /** Creates a matrix from three row vector values */
  eImplicitNodeTypeDot = 13, /** Calculates the dot product of two vector values */
  eImplicitNodeTypeCross = 14, /** Calculates the cross product of two vector values */
  eImplicitNodeTypeMatVecMultiplication = 15, /** Multiplies a matrix with a vector */
  eImplicitNodeTypeTranspose = 16, /** Transposes a matrix */
  eImplicitNodeTypeInverse = 17, /** Computes the inverse of a matrix */
  eImplicitNodeTypeSinus = 18, /** Calculates the sinus */
  eImplicitNodeTypeCosinus = 19, /** Calculates the cosinus */
  eImplicitNodeTypeTan = 20, /** Calculates the tangent */
  eImplicitNodeTypeArcSin = 21, /** Calculates the arcsinus */
  eImplicitNodeTypeArcCos = 22, /** Calculates the arccosinus */
  eImplicitNodeTypeArcTan = 23, /** Calculates the arctangent */
  eImplicitNodeTypeArcTan2 = 24, /** Calculates the arctangent */
  eImplicitNodeTypeMin = 25, /** Calculates the minimum tow values */
  eImplicitNodeTypeMax = 26, /** Calculates the maximum of two values */
  eImplicitNodeTypeAbs = 27, /** Calcul the absolute value */
  eImplicitNodeTypeFmod = 28, /** Computes the remainder of the divison of the inputs (same behavior as C fmod) */
  eImplicitNodeTypePow = 29, /** Calculates the power A^B */
  eImplicitNodeTypeSqrt = 30, /** Calculates the square root */
  eImplicitNodeTypeExp = 31, /** Exponential function */
  eImplicitNodeTypeLog = 32, /** Natural logarithmus */
  eImplicitNodeTypeLog2 = 33, /** Logarithmus to the base 2 */
  eImplicitNodeTypeLog10 = 34, /** Logarithmus to the base 10 */
  eImplicitNodeTypeSelect = 35, /** If A is less B returns C, else D */
  eImplicitNodeTypeClamp = 36, /** Clamps the input value to min and max */
  eImplicitNodeTypeSinh = 37, /** Calculates the hyperbolic sine */
  eImplicitNodeTypeCosh = 38, /** Calculates the hyperbolic cosine */
  eImplicitNodeTypeTanh = 39, /** Calculates the hyperbolic tangent */
  eImplicitNodeTypeRound = 40, /** Rounds a scalar value to the nearest integer */
  eImplicitNodeTypeCeil = 41, /** Rounds a scalar value up to the nearest integer */
  eImplicitNodeTypeFloor = 42, /** Rounds a scalar value down to the nearest integer */
  eImplicitNodeTypeSign = 43, /** Returns the sign */
  eImplicitNodeTypeFract = 44, /** Returns the fractional part */
  eImplicitNodeTypeFunctionCall = 45, /** Calls a function */
  eImplicitNodeTypeMesh = 46, /** Calculates the signed distance to a mesh */
  eImplicitNodeTypeLength = 47, /** Calculates the length of a vector */
  eImplicitNodeTypeConstResourceID = 48, /** Selects a resource (function, mesh etc.) */
  eImplicitNodeTypeVectorFromScalar = 49, /** Creates a vector from one scalar values */
  eImplicitNodeTypeUnsignedMesh = 50, /** Calculates the unsigned distance to a mesh */
  eImplicitNodeTypeMod = 51 /** Calculates the modulo of two values (same behaviour as glsl mod) */
} eLib3MFImplicitNodeType;

/**
* enum eLib3MFImplicitPortType - The type of the port
*/
typedef enum eLib3MFImplicitPortType {
  eImplicitPortTypeScalar = 1, /** Scalar */
  eImplicitPortTypeVector = 2, /** Vector */
  eImplicitPortTypeMatrix = 3, /** 4x4 Matrix */
  eImplicitPortTypeResourceID = 4 /** Resource ID */
} eLib3MFImplicitPortType;

/**
* enum eLib3MFImplicitNodeConfiguration - Defines the input and output types of a node
*/
typedef enum eLib3MFImplicitNodeConfiguration {
  eImplicitNodeConfigurationDefault = 1, /** Default */
  eImplicitNodeConfigurationScalarToScalar = 2, /** Scalar -> Scalar */
  eImplicitNodeConfigurationVectorToVector = 3, /** Vector -> Vector */
  eImplicitNodeConfigurationMatrixToMatrix = 4 /** Matrix -> Matrix */
} eLib3MFImplicitNodeConfiguration;

typedef enum eLib3MFEncryptionAlgorithm {
  eEncryptionAlgorithmAES256_GCM = 1 /** http://www.w3.org/2009/xmlenc11#aes256-gcm */
} eLib3MFEncryptionAlgorithm;

typedef enum eLib3MFWrappingAlgorithm {
  eWrappingAlgorithmRSA_OAEP = 0 /** http://www.w3.org/2009/xmlenc11#rsa-oaep */
} eLib3MFWrappingAlgorithm;

typedef enum eLib3MFMgfAlgorithm {
  eMgfAlgorithmMGF1_SHA1 = 160, /** http://www.w3.org/2009/xmlenc11#mgf1sha1 */
  eMgfAlgorithmMGF1_SHA224 = 224, /** http://www.w3.org/2009/xmlenc11#mgf1sha224 */
  eMgfAlgorithmMGF1_SHA256 = 256, /** http://www.w3.org/2009/xmlenc11#mgf1sha256 */
  eMgfAlgorithmMGF1_SHA384 = 384, /** http://www.w3.org/2009/xmlenc11#mgf1sha384 */
  eMgfAlgorithmMGF1_SHA512 = 512 /** http://www.w3.org/2009/xmlenc11#mgf1sha512 */
} eLib3MFMgfAlgorithm;

typedef enum eLib3MFDigestMethod {
  eDigestMethodSHA1 = 160, /** http://www.w3.org/2000/09/xmldsig#sha1 */
  eDigestMethodSHA256 = 256 /** http://www.w3.org/2001/04/xmlenc#sha256 */
} eLib3MFDigestMethod;

typedef enum eLib3MFCompression {
  eCompressionNoCompression = 0, /** No compression applied */
  eCompressionDeflate = 1 /** Deflate compression applied */
} eLib3MFCompression;

/*************************************************************************************************************************
 Declaration of enum members for 4 byte struct alignment
**************************************************************************************************************************/

typedef union {
  eLib3MFPropertyType m_enum;
  int m_code;
} structEnumLib3MFPropertyType;

typedef union {
  eLib3MFSlicesMeshResolution m_enum;
  int m_code;
} structEnumLib3MFSlicesMeshResolution;

typedef union {
  eLib3MFModelUnit m_enum;
  int m_code;
} structEnumLib3MFModelUnit;

typedef union {
  eLib3MFObjectType m_enum;
  int m_code;
} structEnumLib3MFObjectType;

typedef union {
  eLib3MFTextureType m_enum;
  int m_code;
} structEnumLib3MFTextureType;

typedef union {
  eLib3MFTextureTileStyle m_enum;
  int m_code;
} structEnumLib3MFTextureTileStyle;

typedef union {
  eLib3MFTextureFilter m_enum;
  int m_code;
} structEnumLib3MFTextureFilter;

typedef union {
  eLib3MFBeamLatticeCapMode m_enum;
  int m_code;
} structEnumLib3MFBeamLatticeCapMode;

typedef union {
  eLib3MFBeamLatticeClipMode m_enum;
  int m_code;
} structEnumLib3MFBeamLatticeClipMode;

typedef union {
  eLib3MFBeamLatticeBallMode m_enum;
  int m_code;
} structEnumLib3MFBeamLatticeBallMode;

typedef union {
  eLib3MFProgressIdentifier m_enum;
  int m_code;
} structEnumLib3MFProgressIdentifier;

typedef union {
  eLib3MFBlendMethod m_enum;
  int m_code;
} structEnumLib3MFBlendMethod;

typedef union {
  eLib3MFChannelName m_enum;
  int m_code;
} structEnumLib3MFChannelName;

typedef union {
  eLib3MFCompositionMethod m_enum;
  int m_code;
} structEnumLib3MFCompositionMethod;

typedef union {
  eLib3MFCompositionSpace m_enum;
  int m_code;
} structEnumLib3MFCompositionSpace;

typedef union {
  eLib3MFImplicitNodeType m_enum;
  int m_code;
} structEnumLib3MFImplicitNodeType;

typedef union {
  eLib3MFImplicitPortType m_enum;
  int m_code;
} structEnumLib3MFImplicitPortType;

typedef union {
  eLib3MFImplicitNodeConfiguration m_enum;
  int m_code;
} structEnumLib3MFImplicitNodeConfiguration;

typedef union {
  eLib3MFEncryptionAlgorithm m_enum;
  int m_code;
} structEnumLib3MFEncryptionAlgorithm;

typedef union {
  eLib3MFWrappingAlgorithm m_enum;
  int m_code;
} structEnumLib3MFWrappingAlgorithm;

typedef union {
  eLib3MFMgfAlgorithm m_enum;
  int m_code;
} structEnumLib3MFMgfAlgorithm;

typedef union {
  eLib3MFDigestMethod m_enum;
  int m_code;
} structEnumLib3MFDigestMethod;

typedef union {
  eLib3MFCompression m_enum;
  int m_code;
} structEnumLib3MFCompression;

/*************************************************************************************************************************
 Declaration of structs
**************************************************************************************************************************/

#pragma pack (1)

typedef struct sLib3MFTriangle {
    Lib3MF_uint32 m_Indices[3];
} sLib3MFTriangle;

typedef struct sLib3MFTriangleProperties {
    Lib3MF_uint32 m_ResourceID;
    Lib3MF_uint32 m_PropertyIDs[3];
} sLib3MFTriangleProperties;

typedef struct sLib3MFPosition {
    Lib3MF_single m_Coordinates[3];
} sLib3MFPosition;

typedef struct sLib3MFPosition2D {
    Lib3MF_single m_Coordinates[2];
} sLib3MFPosition2D;

typedef struct sLib3MFCompositeConstituent {
    Lib3MF_uint32 m_PropertyID;
    Lib3MF_double m_MixingRatio;
} sLib3MFCompositeConstituent;

typedef struct sLib3MFMultiPropertyLayer {
    Lib3MF_uint32 m_ResourceID;
    structEnumLib3MFBlendMethod m_TheBlendMethod;
} sLib3MFMultiPropertyLayer;

typedef struct sLib3MFTex2Coord {
    Lib3MF_double m_U;
    Lib3MF_double m_V;
} sLib3MFTex2Coord;

typedef struct sLib3MFTransform {
    Lib3MF_single m_Fields[4][3];
} sLib3MFTransform;

typedef struct sLib3MFBox {
    Lib3MF_single m_MinCoordinate[3];
    Lib3MF_single m_MaxCoordinate[3];
} sLib3MFBox;

typedef struct sLib3MFColor {
    Lib3MF_uint8 m_Red;
    Lib3MF_uint8 m_Green;
    Lib3MF_uint8 m_Blue;
    Lib3MF_uint8 m_Alpha;
} sLib3MFColor;

typedef struct sLib3MFBeam {
    Lib3MF_uint32 m_Indices[2];
    Lib3MF_double m_Radii[2];
    structEnumLib3MFBeamLatticeCapMode m_CapModes[2];
} sLib3MFBeam;

typedef struct sLib3MFBall {
    Lib3MF_uint32 m_Index;
    Lib3MF_double m_Radius;
} sLib3MFBall;

typedef struct sLib3MFVector {
    Lib3MF_double m_Coordinates[3];
} sLib3MFVector;

typedef struct sLib3MFMatrix4x4 {
    Lib3MF_double m_Field[4][4];
} sLib3MFMatrix4x4;

#pragma pack ()

/*************************************************************************************************************************
 Declaration of function pointers 
**************************************************************************************************************************/

/**
* Lib3MFProgressCallback - A callback function
*
* @param[out] pAbort - Returns whether the calculation should be aborted
* @param[in] dProgressValue - The value of the progress function: values in the interval [0,1] are progress; < mean no progress update
* @param[in] eProgressIdentifier - An identifier of progress
* @param[in] pUserData - Userdata that is passed to the callback function
*/
typedef void(*Lib3MFProgressCallback)(bool *, Lib3MF_double, eLib3MFProgressIdentifier, Lib3MF_pvoid);

/**
* Lib3MFWriteCallback - Callback to call for writing a data chunk
*
* @param[in] nByteData - Pointer to the data to be written
* @param[in] nNumBytes - Number of bytes to write
* @param[in] pUserData - Userdata that is passed to the callback function
*/
typedef void(*Lib3MFWriteCallback)(Lib3MF_uint64, Lib3MF_uint64, Lib3MF_pvoid);

/**
* Lib3MFReadCallback - Callback to call for reading a data chunk
*
* @param[in] nByteData - Pointer to a buffer to read data into
* @param[in] nNumBytes - Number of bytes to read
* @param[in] pUserData - Userdata that is passed to the callback function
*/
typedef void(*Lib3MFReadCallback)(Lib3MF_uint64, Lib3MF_uint64, Lib3MF_pvoid);

/**
* Lib3MFSeekCallback - Callback to call for seeking in the stream
*
* @param[in] nPosition - Position in the stream to move to
* @param[in] pUserData - Userdata that is passed to the callback function
*/
typedef void(*Lib3MFSeekCallback)(Lib3MF_uint64, Lib3MF_pvoid);

/**
* Lib3MFRandomNumberCallback - Callback to generate random numbers
*
* @param[in] nByteData - Pointer to a buffer to read data into
* @param[in] nNumBytes - Size of available bytes in the buffer
* @param[in] pUserData - Userdata that is passed to the callback function
* @param[out] pBytesWritten - Number of bytes generated when succeed. 0 or less if failed.
*/
typedef void(*Lib3MFRandomNumberCallback)(Lib3MF_uint64, Lib3MF_uint64, Lib3MF_pvoid, Lib3MF_uint64 *);

/**
* Lib3MFKeyWrappingCallback - A callback used to wrap (encrypt) the content key available in keystore resource group
*
* @param[in] pKEKParams - The information about the parameters used used to wrap the key to the contents
* @param[in] nInBufferBufferSize - Number of elements in buffer
* @param[in] pInBufferBuffer - uint8 buffer of Buffer to the input value. When encrypting, this should be the plain key. When decrypting, this should be the key cipher.
* @param[in] nOutBufferBufferSize - Number of elements in buffer
* @param[out] pOutBufferNeededCount - will be filled with the count of the written elements, or needed buffer size.
* @param[out] pOutBufferBuffer - uint8  buffer of Buffer where the data will be placed. When encrypting, this will be the key cipher. When decrypting, this will be the plain key. When buffer is null, neededBytes contains the required bytes to run.
* @param[in] pUserData - Userdata that is passed to the callback function
* @param[out] pStatus - The needed/encrypted/decrypted bytes when succeed or zero when error.
*/
typedef void(*Lib3MFKeyWrappingCallback)(Lib3MF_AccessRight, Lib3MF_uint64, const Lib3MF_uint8 *, const Lib3MF_uint64, Lib3MF_uint64*, Lib3MF_uint8 *, Lib3MF_pvoid, Lib3MF_uint64 *);

/**
* Lib3MFContentEncryptionCallback - A callback to encrypt/decrypt content called on each resource encrypted. This might be called several times depending on content size. If Input is not available(either null or size is 0), clients must return the result of authenticated tag generation/validation.
*
* @param[in] pCEKParams - The params of the encryption process. Client must set/check AuthenticationTag when closing the encryption/decryption process.
* @param[in] nInputBufferSize - Number of elements in buffer
* @param[in] pInputBuffer - uint8 buffer of Buffer to the original data. In encrypting, this will be the plain data. If decrypting, this will be the cipher data
* @param[in] nOutputBufferSize - Number of elements in buffer
* @param[out] pOutputNeededCount - will be filled with the count of the written elements, or needed buffer size.
* @param[out] pOutputBuffer - uint8  buffer of Buffer to hold the transformed data. When encrypting, this will be the cipher data. When decrypting, this shall be the plain data. If buffer is null, neededBytes return the necessary amount of bytes.
* @param[in] pUserData - Userdata that is passed to the callback function
* @param[out] pStatus - The needed/encrypted/decrypted/verified bytes when succeed or zero when error.
*/
typedef void(*Lib3MFContentEncryptionCallback)(Lib3MF_ContentEncryptionParams, Lib3MF_uint64, const Lib3MF_uint8 *, const Lib3MF_uint64, Lib3MF_uint64*, Lib3MF_uint8 *, Lib3MF_pvoid, Lib3MF_uint64 *);


#endif // __LIB3MF_TYPES_HEADER
