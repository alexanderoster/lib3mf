/*++

Copyright (C) 2018 3MF Consortium (Original Author)

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

Abstract: This is a stub class definition of CLib3MFBeamLattice

*/

#include "lib3mf_beamlattice.hpp"
#include "lib3mf_interfaceexception.hpp"

// Include custom headers here.


using namespace Lib3MF::Impl;

/*************************************************************************************************************************
 Class definition of CLib3MFBeamLattice 
**************************************************************************************************************************/

CLib3MFBeamLattice::CLib3MFBeamLattice(NMR::PModelMeshObject pMeshObject, NMR::PModelMeshBeamLatticeAttributes pAttributes):
	m_pMeshObject(pMeshObject),m_mesh(*pMeshObject->getMesh()), m_pAttributes(pAttributes)
{
	
}

Lib3MF_double CLib3MFBeamLattice::GetMinLength ()
{
	return m_mesh.getBeamLatticeMinLength();
}

void CLib3MFBeamLattice::SetMinLength (const Lib3MF_double dMinLength)
{
	return m_mesh.setBeamLatticeMinLength(dMinLength);
}

void CLib3MFBeamLattice::GetClipping (eLib3MFBeamLatticeClipMode & eClipMode, Lib3MF_uint32 & nResourceID)
{
	
	if (!m_pAttributes->m_bHasClippingMeshID) {
		eClipMode = eLib3MFBeamLatticeClipMode::eBeamLatticeClipModeNoClipMode;
		nResourceID = 0;
	}
	else {
		eClipMode = eLib3MFBeamLatticeClipMode(m_pAttributes->m_eClipMode);
		nResourceID = m_pAttributes->m_nClippingMeshID->getUniqueID();
	}
}

void CLib3MFBeamLattice::SetClipping (const eLib3MFBeamLatticeClipMode eClipMode, const Lib3MF_uint32 nResourceID)
{
	if ( (eClipMode == NMR::eModelBeamLatticeClipMode::MODELBEAMLATTICECLIPMODE_NONE) || (nResourceID == 0) ){
		m_pAttributes->m_eClipMode = NMR::eModelBeamLatticeClipMode(eClipMode);
		m_pAttributes->m_bHasClippingMeshID = false;
		m_pAttributes->m_nClippingMeshID = nullptr;
	}
	else {
		NMR::CModel* pModel = m_pMeshObject->getModel();

		NMR::CModelMeshObject * pClippingObject = dynamic_cast<NMR::CModelMeshObject*>(pModel->findObject(nResourceID));
		if (pClippingObject == nullptr) {
			throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
		}
		// check, if this object will be written before 
		NMR::nfInt32 nComp = pModel->compareObjectsByResourceID(pClippingObject, m_pMeshObject.get());
		if (nComp < 0) { // pClippingObject has been defined after m_pMeshObject
			throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
		}

		m_pAttributes->m_eClipMode = NMR::eModelBeamLatticeClipMode(eClipMode);;
		m_pAttributes->m_bHasClippingMeshID = true;
		m_pAttributes->m_nClippingMeshID = pClippingObject->getResourceID();
	}
}

bool CLib3MFBeamLattice::GetRepresentation (Lib3MF_uint32 & nResourceID)
{
	if (!m_pAttributes->m_bHasRepresentationMeshID) {
		nResourceID = 0;
		return false;
	}
	else {
		nResourceID = m_pAttributes->m_nRepresentationID->getUniqueID();
		return true;
	}
}

void CLib3MFBeamLattice::SetRepresentation (const Lib3MF_uint32 nResourceID)
{
	if (nResourceID == 0) {
		m_pAttributes->m_bHasRepresentationMeshID = false;
		m_pAttributes->m_nRepresentationID = nullptr;
	}
	else {
		NMR::CModel* pModel = m_pMeshObject->getModel();

		NMR::CModelMeshObject * pRepresentationObject = dynamic_cast<NMR::CModelMeshObject*>(pModel->findObject(nResourceID));
		if (pRepresentationObject == nullptr) {
			throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
		}
		// check, if this object will be written before 
		NMR::nfInt32 nComp = pModel->compareObjectsByResourceID(pRepresentationObject, m_pMeshObject.get());
		if (nComp < 0) { // pClippingObject has been defined after m_pMeshObject
			throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
		}

		m_pAttributes->m_bHasRepresentationMeshID = true;
		m_pAttributes->m_nRepresentationID = pRepresentationObject->getResourceID();
	}
}

Lib3MF_uint32 CLib3MFBeamLattice::GetBeamCount ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

sLib3MFBeam CLib3MFBeamLattice::GetBeam (const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

Lib3MF_uint32 CLib3MFBeamLattice::AddBeam (const sLib3MFBeam BeamInfo)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFBeamLattice::SetBeam (const Lib3MF_uint32 nIndex, const sLib3MFBeam BeamInfo)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFBeamLattice::SetBeams (const Lib3MF_uint64 nBeamInfoBufferSize, const sLib3MFBeam * pBeamInfoBuffer)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFBeamLattice::GetBeams (Lib3MF_uint64 nBeamInfoBufferSize, Lib3MF_uint64* pBeamInfoNeededCount, sLib3MFBeam * pBeamInfoBuffer)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

Lib3MF_uint32 CLib3MFBeamLattice::GetBeamSetCount ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFBeamSet * CLib3MFBeamLattice::AddBeamSet ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFBeamSet * CLib3MFBeamLattice::GetBeamSet (const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

