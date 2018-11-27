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

Abstract: This is a stub class definition of CLib3MFModel

*/

#include "lib3mf_model.hpp"
#include "lib3mf_interfaceexception.hpp"

#include "lib3mf_reader.hpp"
#include "lib3mf_writer.hpp"

#include "lib3mf_builditemiterator.hpp"
#include "lib3mf_meshobject.hpp"
#include "lib3mf_componentsobject.hpp"
// Include custom headers here.

#include "Model/Classes/NMR_ModelMeshObject.h"
#include "Model/Classes/NMR_ModelComponentsObject.h"


using namespace Lib3MF;

/*************************************************************************************************************************
 Class definition of CLib3MFModel 
**************************************************************************************************************************/


CLib3MFModel::CLib3MFModel()
{
	m_model = std::make_shared<NMR::CModel>();
}

NMR::CModel& CLib3MFModel::model()
{
	return *m_model;
}

void CLib3MFModel::SetUnit (const eLib3MFModelUnit eUnit)
{
	model().setUnit(NMR::eModelUnit(eUnit));
}

eLib3MFModelUnit CLib3MFModel::GetUnit ()
{
	return eLib3MFModelUnit(model().getUnit());
}

std::string CLib3MFModel::GetLanguage ()
{
	return model().getLanguage();
}

void CLib3MFModel::SetLanguage (const std::string & sLanguage)
{
	model().setLanguage(sLanguage);
}

ILib3MFWriter * CLib3MFModel::QueryWriter (const std::string & sWriterClass)
{
	return new CLib3MFWriter(sWriterClass, m_model);
}

ILib3MFReader * CLib3MFModel::QueryReader (const std::string & sReaderClass)
{
	return new CLib3MFReader(sReaderClass, m_model);
}

ILib3MFResource * CLib3MFModel::GetResourceByID (const Lib3MF_uint32 nResourceID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFTexture2D * CLib3MFModel::GetTexture2DByID (const Lib3MF_uint32 nResourceID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFBaseMaterial * CLib3MFModel::GetBaseMaterialByID (const Lib3MF_uint32 nResourceID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFMeshObject * CLib3MFModel::GetMeshObjectByID (const Lib3MF_uint32 nResourceID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFComponentsObject * CLib3MFModel::GetComponentsObjectByID (const Lib3MF_uint32 nResourceID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

std::string CLib3MFModel::GetBuildUUID (bool & bHasUUID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFModel::SetBuildUUID (const std::string & sUUID)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFBuildItemIterator * CLib3MFModel::GetBuildItems ()
{
	auto pResult = std::make_unique<CLib3MFBuildItemIterator>();
	Lib3MF_uint32 nBuildItemCount = m_model->getBuildItemCount();
	Lib3MF_uint32 nIdx;

	for (nIdx = 0; nIdx < nBuildItemCount; nIdx++)
		pResult->addBuildItem(m_model->getBuildItem(nIdx));

	return pResult.release();
}

ILib3MFResourceIterator * CLib3MFModel::GetResources ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFResourceIterator * CLib3MFModel::GetObjects ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFResourceIterator * CLib3MFModel::GetMeshObjects ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFResourceIterator * CLib3MFModel::GetComponentsObjects ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFResourceIterator * CLib3MFModel::Get2DTextures ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFResourceIterator * CLib3MFModel::GetBaseMaterials ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFModel * CLib3MFModel::MergeToModel ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFMeshObject * CLib3MFModel::AddMeshObject ()
{
	NMR::ModelResourceID NewResourceID = model().generateResourceID();
	NMR::PMesh pNewMesh = std::make_shared<NMR::CMesh>();
	NMR::PModelMeshObject pNewResource = std::make_shared<NMR::CModelMeshObject>(NewResourceID, &model(), pNewMesh);

	model().addResource(pNewResource);
	return new CLib3MFMeshObject(pNewResource);
}

ILib3MFComponentsObject * CLib3MFModel::AddComponentsObject ()
{
	NMR::ModelResourceID NewResourceID = model().generateResourceID();
	NMR::PModelComponentsObject pNewResource = std::make_shared<NMR::CModelComponentsObject>(NewResourceID, &model());

	model().addResource(pNewResource);
	return new CLib3MFComponentsObject(pNewResource);
}

ILib3MFTexture2D * CLib3MFModel::AddTexture2DFromAttachment (ILib3MFAttachment* pTextureAttachment)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFBaseMaterial * CLib3MFModel::AddBaseMaterialGroup ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFBuildItem * CLib3MFModel::AddBuildItem (ILib3MFObject* pObject, const sLib3MFTransform Transform)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFModel::RemoveBuildItem (ILib3MFBuildItem* pBuildItemInstance)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFMetaDataGroup * CLib3MFModel::GetMetaDataGroup ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFAttachment * CLib3MFModel::AddAttachment (const std::string & sURI, const std::string & sRelationShipType)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFAttachment * CLib3MFModel::GetAttachment (const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFAttachment * CLib3MFModel::FindAttachment (const std::string & sURI)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

Lib3MF_uint32 CLib3MFModel::GetAttachmentCount ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

Lib3MF_uint64 CLib3MFModel::GetAttachmentSize (const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

std::string CLib3MFModel::GetAttachmentPath (const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

bool CLib3MFModel::HasPackageThumbnailAttachment ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFAttachment * CLib3MFModel::CreatePackageThumbnailAttachment ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

ILib3MFAttachment * CLib3MFModel::GetPackageThumbnailAttachment ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFModel::RemovePackageThumbnailAttachment ()
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFModel::AddCustomContentType (const std::string & sExtension, const std::string & sContentType)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFModel::RemoveCustomContentType (const std::string & sExtension)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

