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

Abstract: This is a stub class definition of CLib3MFResource

*/

#include "lib3mf_resource.hpp"
#include "lib3mf_interfaceexception.hpp"

// Include custom headers here.
#include "Model/Classes/NMR_ModelObject.h"
#include "lib3mf_object.hpp"
#include <iostream>

using namespace Lib3MF;

/*************************************************************************************************************************
 Class definition of CLib3MFResource 
**************************************************************************************************************************/


NMR::PModelResource CLib3MFResource::resource()
{
	if (m_pResource.get()==nullptr)
		throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDOBJECT);

	return m_pResource;
}

CLib3MFResource::CLib3MFResource(NMR::PModelResource pResource)
{
	if (pResource.get() == nullptr)
		throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDMODELRESOURCE);
	m_pResource = pResource;
}

Lib3MF_uint32 CLib3MFResource::GetResourceID ()
{
	return m_pResource->getResourceID()->getUniqueID();
}

ILib3MFObject * CLib3MFResource::AsObject()
{
	if (dynamic_cast<NMR::CModelObject*>(m_pResource.get()))
	{
		return new CLib3MFObject(m_pResource);
	}
	throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDCAST);
}

