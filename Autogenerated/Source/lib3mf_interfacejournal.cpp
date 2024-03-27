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

Abstract: This is an autogenerated C++ implementation file in order to allow easy
development of the 3MF Library. It provides an automatic Journaling mechanism for the library implementation.

Interface version: 2.4.0

*/


#include <string>
#include <sstream>
#include <iomanip>

#include "lib3mf_interfacejournal.hpp"
#include "lib3mf_interfaceexception.hpp"


std::string Lib3MFHandleToHex (Lib3MFHandle pHandle)
{
	std::stringstream stream;
	stream << std::setfill('0') << std::setw(sizeof(Lib3MF_uint64) * 2)
		<< std::hex << (Lib3MF_uint64) pHandle;
	return stream.str();
}

CLib3MFInterfaceJournalEntry::CLib3MFInterfaceJournalEntry(CLib3MFInterfaceJournal * pJournal, std::string sClassName, std::string sMethodName, Lib3MFHandle pInstanceHandle)
	: m_pJournal(pJournal), m_ErrorCode(LIB3MF_SUCCESS), m_sClassName(sClassName), m_sMethodName(sMethodName), m_nInitTimeStamp(0), m_nFinishTimeStamp(0)
{
	if (pJournal == nullptr)
		throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
	m_nInitTimeStamp = m_pJournal->getTimeStamp ();
	m_sInstanceHandle = Lib3MFHandleToHex (pInstanceHandle);
}

CLib3MFInterfaceJournalEntry::~CLib3MFInterfaceJournalEntry()
{
}

void CLib3MFInterfaceJournalEntry::addParameter(const std::string & sName, const std::string & sParameterType, const std::string & sParameterValue)
{
	m_sParameters.push_back(std::make_pair(std::make_pair(sName, sParameterType), sParameterValue));
}

void CLib3MFInterfaceJournalEntry::addResult(const std::string & sName, const std::string & sResultType, const std::string & sResultValue)
{
	m_sResultValues.push_back(std::make_pair(std::make_pair(sName, sResultType), sResultValue));
}

std::string CLib3MFInterfaceJournalEntry::getXMLString()
{
	std::stringstream sStream;
	Lib3MF_uint64 nDuration = 0;

	if (m_nFinishTimeStamp > m_nInitTimeStamp)
		nDuration = m_nFinishTimeStamp - m_nInitTimeStamp;

	sStream << "    <entry";
	if (m_sClassName != "")
		sStream << " class=\"" << m_sClassName << "\"";
	sStream << " method=\"" << m_sMethodName << "\"";
	if (m_ErrorCode != LIB3MF_SUCCESS)
		sStream << " errorcode=\"" << m_ErrorCode << "\"";
	sStream << " timestamp=\"" << m_nInitTimeStamp << "\" duration=\"" << nDuration << "\">\n";

	if (m_sClassName != "")
		sStream << "        <instance handle=\"" << m_sInstanceHandle << "\" />\n";

	auto iParamIter = m_sParameters.begin();
	while (iParamIter != m_sParameters.end()) {
		sStream << "        <parameter name=\"" << iParamIter->first.first << "\" type=\"" << iParamIter->first.second << "\" value=\"" << iParamIter->second <<"\" />\n";
		iParamIter++;
	}

	auto iResultIter = m_sResultValues.begin();
	while (iResultIter != m_sResultValues.end()) {
		sStream << "        <result name=\"" << iResultIter->first.first << "\" type=\"" << iResultIter->first.second << "\" value=\"" << iResultIter->second << "\" />\n";
		iResultIter++;
	}

	sStream << "    </entry>\n";
	return sStream.str ();
}

void CLib3MFInterfaceJournalEntry::writeSuccess()
{
	writeError(LIB3MF_SUCCESS);
}

void CLib3MFInterfaceJournalEntry::writeError(Lib3MFResult nErrorCode)
{
	m_ErrorCode = nErrorCode;
	m_nFinishTimeStamp = m_pJournal->getTimeStamp();
	m_pJournal->writeEntry(this);
}

void CLib3MFInterfaceJournalEntry::addBooleanParameter(const std::string & sName, const bool bValue)
{
	addParameter (sName, "bool", std::to_string((int)bValue));
}

void CLib3MFInterfaceJournalEntry::addUInt8Parameter(const std::string & sName, const Lib3MF_uint8 nValue)
{
	addParameter(sName, "uint8", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addUInt16Parameter(const std::string & sName, const Lib3MF_uint16 nValue)
{
	addParameter(sName, "uint16", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addUInt32Parameter(const std::string & sName, const Lib3MF_uint32 nValue)
{
	addParameter(sName, "uint32", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addUInt64Parameter(const std::string & sName, const Lib3MF_uint64 nValue)
{
	addParameter(sName, "uint64", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt8Parameter(const std::string & sName, const Lib3MF_int8 nValue)
{
	addParameter(sName, "int8", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt16Parameter(const std::string & sName, const Lib3MF_int16 nValue)
{
	addParameter(sName, "int16", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt32Parameter(const std::string & sName, const Lib3MF_int32 nValue)
{
	addParameter(sName, "uint32", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt64Parameter(const std::string & sName, const Lib3MF_int64 nValue)
{
	addParameter(sName, "int64", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addSingleParameter(const std::string & sName,  const Lib3MF_single fValue)
{
	addParameter(sName, "single", std::to_string(fValue));
}

void CLib3MFInterfaceJournalEntry::addDoubleParameter(const std::string & sName, const Lib3MF_double dValue)
{
	addParameter(sName, "double", std::to_string(dValue));
}
void CLib3MFInterfaceJournalEntry::addPointerParameter(const std::string & sName, const Lib3MF_pvoid pValue)
{
	addParameter(sName, "pointer", std::to_string(reinterpret_cast<const Lib3MF_uint64>(pValue)));
}

void CLib3MFInterfaceJournalEntry::addStringParameter(const std::string & sName, const char * pValue)
{
	if (pValue != nullptr) {
		addParameter(sName, "string", pValue);
	}
	else {
		addParameter(sName, "nullstring", "");
	}
}

void CLib3MFInterfaceJournalEntry::addHandleParameter(const std::string & sName, const Lib3MFHandle pHandle)
{
	addParameter(sName, "handle", Lib3MFHandleToHex(pHandle));
}

void CLib3MFInterfaceJournalEntry::addEnumParameter(const std::string & sName, const std::string & sEnumType, const Lib3MF_int32 nValue)
{
	addParameter(sName, "enum" + sEnumType, std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addBooleanResult(const std::string & sName, const bool bValue)
{
	addResult(sName, "bool", std::to_string((int)bValue));
}

void CLib3MFInterfaceJournalEntry::addUInt8Result(const std::string & sName, const Lib3MF_uint8 nValue)
{
	addResult(sName, "uint8", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addUInt16Result(const std::string & sName, const Lib3MF_uint16 nValue)
{
	addResult(sName, "uint16", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addUInt32Result(const std::string & sName, const Lib3MF_uint32 nValue)
{
	addResult(sName, "uint32", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addUInt64Result(const std::string & sName, const Lib3MF_uint64 nValue)
{
	addResult(sName, "uint64", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt8Result(const std::string & sName, const Lib3MF_int8 nValue)
{
	addResult(sName, "int8", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt16Result(const std::string & sName, const Lib3MF_int16 nValue)
{
	addResult(sName, "int16", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt32Result(const std::string & sName, const Lib3MF_int32 nValue)
{
	addResult(sName, "uint32", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addInt64Result(const std::string & sName, const Lib3MF_int64 nValue)
{
	addResult(sName, "int64", std::to_string(nValue));
}

void CLib3MFInterfaceJournalEntry::addSingleResult(const std::string & sName,  const Lib3MF_single fValue)
{
	addResult(sName, "single", std::to_string(fValue));
}

void CLib3MFInterfaceJournalEntry::addDoubleResult(const std::string & sName, const Lib3MF_double dValue)
{
	addResult(sName, "double", std::to_string(dValue));
}

void CLib3MFInterfaceJournalEntry::addPointerResult(const std::string & sName, const Lib3MF_pvoid pValue)
{
	addResult(sName, "pointer", std::to_string(reinterpret_cast<const Lib3MF_uint64>(pValue)));
}

void CLib3MFInterfaceJournalEntry::addStringResult(const std::string & sName, const char * pValue)
{
	if (pValue != nullptr) {
		addResult(sName, "string", pValue);
	}
	else {
		addResult(sName, "nullstring", "");
	}
}

void CLib3MFInterfaceJournalEntry::addHandleResult(const std::string & sName, const Lib3MFHandle pHandle)
{
	addResult(sName, "handle", Lib3MFHandleToHex(pHandle));
}

void CLib3MFInterfaceJournalEntry::addEnumResult(const std::string & sName, const std::string & sEnumType, const Lib3MF_int32 nValue)
{
	addResult(sName, "enum" + sEnumType, std::to_string(nValue));
}


CLib3MFInterfaceJournal::CLib3MFInterfaceJournal (const std::string & sFileName)
	: m_sFileName (sFileName)
{
	m_StartTime = std::chrono::high_resolution_clock::now();
	m_Stream.open (sFileName, std::ios::out);
	m_Stream << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
	m_Stream << "<journal library=\"Lib3MF\" version=\"2.4.0-implicit\" xmlns=\"http://schemas.autodesk.com/components/Lib3MF/2.4.0-implicit\">\n";
	m_Stream << "\n";

}

CLib3MFInterfaceJournal::~CLib3MFInterfaceJournal ()
{
	m_Stream << "</journal>\n";
}

PLib3MFInterfaceJournalEntry CLib3MFInterfaceJournal::beginClassMethod(const Lib3MFHandle pHandle, const std::string & sClassName, const std::string & sMethodName)
{
	return std::make_shared<CLib3MFInterfaceJournalEntry>(this, sClassName, sMethodName, pHandle);
}

PLib3MFInterfaceJournalEntry CLib3MFInterfaceJournal::beginStaticFunction(const std::string & sMethodName)
{
	return std::make_shared<CLib3MFInterfaceJournalEntry>(this, "", sMethodName, nullptr);
}

void CLib3MFInterfaceJournal::writeEntry (CLib3MFInterfaceJournalEntry * pEntry)
{
	if (pEntry == nullptr)
		throw ELib3MFInterfaceException (LIB3MF_ERROR_INVALIDPARAM);

	std::string sXMLString = pEntry->getXMLString();
	m_Mutex.lock();
	try {
		m_Stream << sXMLString;
		m_Stream << "\n";

		m_Mutex.unlock();
	}
	catch (...) {
		m_Mutex.unlock();
	}
}

Lib3MF_uint64 CLib3MFInterfaceJournal::getTimeStamp ()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	if (m_StartTime < currentTime) {
		auto duration = currentTime - m_StartTime;
		auto milliSeconds = std::chrono::duration_cast<std::chrono::milliseconds> (duration);

		return (Lib3MF_uint64) milliSeconds.count();
	}
	else {
		return 0;
	}

}

