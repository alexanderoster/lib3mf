/*++

Copyright (C) 2024 3MF Consortium

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
Reader for boundary shape objects

--*/

#pragma once

#include "Model/Classes/NMR_ImplicitNodeTypes.h"
#include "Model/Classes/NMR_ModelBoundaryShapeObject.h"
#include "Model/Reader/NMR_ModelReaderNode.h"

namespace NMR
{
    class CModelReaderNode_BoundaryShape : public CModelReaderNode
    {
       private:
        PModelBoundaryShapeObject m_pBoundaryShape;
        CModel* m_pModel = nullptr;

        ModelResourceID m_nID = 0;

        nfBool m_bHasFunctionID = false;
        nfBool m_bHasTransform = false;
        nfBool m_bHasChannel = false;
        nfBool m_bHasMeshBBoxOnly = false;
        nfBool m_meshBBoxOnly = false;

        double m_dMinFeatureSize = 0.0;
        nfBool m_bHasMinFeatureSize = false;

        double m_dFallBackValue = 0.0;
        nfBool m_bHasFallBackValue = false;

        ModelResourceID m_nFunctionID;
        NMATRIX3 m_Transform;

        std::string m_sChannel;

        ModelResourceID m_nVolumeDataID = 0;
        nfBool m_bHasVolumeDataID = false;

       public:
        CModelReaderNode_BoundaryShape() = delete;
        CModelReaderNode_BoundaryShape(_In_ CModel* pModel,
                                       _In_ PModelWarnings pWarnings);

        void parseXML(_In_ CXmlReader* pXMLReader) override;

        void OnAttribute(_In_z_ const nfChar* pAttributeName,
                         _In_z_ const nfChar* pAttributeValue) override;

        void OnNSChildElement(_In_z_ const nfChar* pChildName,
                              _In_z_ const nfChar* pNameSpace,
                              _In_ CXmlReader* pXMLReader) override;
    };

    typedef std::shared_ptr<CModelReaderNode_BoundaryShape>
        PModelReaderNode_BoundaryShape;
}  // namespace NMR