/*++

Copyright (C) 2019 3MF Consortium (Original Author)

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

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated plain C Header file with basic types in
order to allow an easy use of the 3MF Library

Interface version: 2.3.0

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
#define LIB3MF_VERSION_MINOR 3
#define LIB3MF_VERSION_MICRO 0
#define LIB3MF_VERSION_PRERELEASEINFO "volumetric"
#define LIB3MF_VERSION_BUILDINFO ""

/*************************************************************************************************************************
 Error constants for Lib3MF
**************************************************************************************************************************/

#define LIB3MF_SUCCESS 0
#define LIB3MF_ERROR_NOTIMPLEMENTED 1
#define LIB3MF_ERROR_INVALIDPARAM 2
#define LIB3MF_ERROR_INVALIDCAST 3
#define LIB3MF_ERROR_BUFFERTOOSMALL 4
#define LIB3MF_ERROR_GENERICEXCEPTION 5
#define LIB3MF_ERROR_COULDNOTLOADLIBRARY 6
#define LIB3MF_ERROR_COULDNOTFINDLIBRARYEXPORT 7
#define LIB3MF_ERROR_INCOMPATIBLEBINARYVERSION 8
#define LIB3MF_ERROR_CALCULATIONABORTED 10
#define LIB3MF_ERROR_SHOULDNOTBECALLED 11
#define LIB3MF_ERROR_READERCLASSUNKNOWN 100
#define LIB3MF_ERROR_WRITERCLASSUNKNOWN 101
#define LIB3MF_ERROR_ITERATORINVALIDINDEX 102
#define LIB3MF_ERROR_INVALIDMODELRESOURCE 103
#define LIB3MF_ERROR_RESOURCENOTFOUND 104
#define LIB3MF_ERROR_INVALIDMODEL 105
#define LIB3MF_ERROR_INVALIDOBJECT 106
#define LIB3MF_ERROR_INVALIDMESHOBJECT 107
#define LIB3MF_ERROR_INVALIDCOMPONENTSOBJECT 108
#define LIB3MF_ERROR_INVALIDCOMPONENT 109
#define LIB3MF_ERROR_INVALIDBUILDITEM 110
#define LIB3MF_ERROR_INVALIDBASEMATERIALGROUP 111
#define LIB3MF_ERROR_INVALIDSLICESTACKRESOURCE 112
#define LIB3MF_ERROR_INVALIDTEXTURERESOURCE 113
#define LIB3MF_ERROR_INVALIDCOLORGROUP 114
#define LIB3MF_ERROR_INVALIDTEXTURE2DGROUP 115
#define LIB3MF_ERROR_INVALIDCOMPOSITEMATERIALS 116
#define LIB3MF_ERROR_INVALIDMULTIPROPERTYGROUP 117
#define LIB3MF_ERROR_INVALIDRESOURCEINDEX 120
#define LIB3MF_ERROR_ATTACHMENTNOTFOUND 121
#define LIB3MF_ERROR_FORBIDDENCYCLICREFERENCE 130
#define LIB3MF_ERROR_INVALIDATTACHMENTSTREAM 131
#define LIB3MF_ERROR_INVALIDPROPERTYCOUNT 132
#define LIB3MF_ERROR_UNKOWNPROGRESSIDENTIFIER 140
#define LIB3MF_ERROR_ELEMENTCOUNTEXCEEDSLIMIT 141
#define LIB3MF_ERROR_BEAMLATTICE_INVALID_OBJECTTYPE 2000
#define LIB3MF_ERROR_INVALIDKEYSTORE 3000
#define LIB3MF_ERROR_INVALIDKEYSTORECONSUMER 3001
#define LIB3MF_ERROR_KEYSTORECONSUMERNOTFOUND 3002
#define LIB3MF_ERROR_KEYSTORERESOURCEDATANOTFOUND 3003
#define LIB3MF_ERROR_SECURECONTEXTNOTREGISTERED 3004

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
typedef Lib3MFHandle Lib3MF_ScalarFieldIterator;
typedef Lib3MFHandle Lib3MF_Vector3DFieldIterator;
typedef Lib3MFHandle Lib3MF_MetaData;
typedef Lib3MFHandle Lib3MF_MetaDataGroup;
typedef Lib3MFHandle Lib3MF_Object;
typedef Lib3MFHandle Lib3MF_MeshObject;
typedef Lib3MFHandle Lib3MF_BeamLattice;
typedef Lib3MFHandle Lib3MF_ScalarField;
typedef Lib3MFHandle Lib3MF_Vector3DField;
typedef Lib3MFHandle Lib3MF_ScalarFieldFromImage3D;
typedef Lib3MFHandle Lib3MF_ScalarFieldConstant;
typedef Lib3MFHandle Lib3MF_ScalarFieldComposed;
typedef Lib3MFHandle Lib3MF_Vector3DFieldFromImage3D;
typedef Lib3MFHandle Lib3MF_Vector3DFieldConstant;
typedef Lib3MFHandle Lib3MF_Vector3DFieldComposed;
typedef Lib3MFHandle Lib3MF_FieldReference;
typedef Lib3MFHandle Lib3MF_ScalarFieldReference;
typedef Lib3MFHandle Lib3MF_Vector3DFieldReference;
typedef Lib3MFHandle Lib3MF_VolumeDataBoundary;
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
  eBeamLatticeBallModeNone = 0,
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

typedef enum eLib3MFEncryptionAlgorithm {
  eEncryptionAlgorithmAES256_GCM = 1
} eLib3MFEncryptionAlgorithm;

typedef enum eLib3MFWrappingAlgorithm {
  eWrappingAlgorithmRSA_OAEP = 0
} eLib3MFWrappingAlgorithm;

typedef enum eLib3MFMgfAlgorithm {
  eMgfAlgorithmMGF1_SHA1 = 160,
  eMgfAlgorithmMGF1_SHA224 = 224,
  eMgfAlgorithmMGF1_SHA256 = 256,
  eMgfAlgorithmMGF1_SHA384 = 384,
  eMgfAlgorithmMGF1_SHA512 = 512
} eLib3MFMgfAlgorithm;

typedef enum eLib3MFDigestMethod {
  eDigestMethodSHA1 = 160,
  eDigestMethodSHA256 = 256
} eLib3MFDigestMethod;

typedef enum eLib3MFCompression {
  eCompressionNoCompression = 0,
  eCompressionDeflate = 1
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

typedef struct {
    Lib3MF_uint32 m_Indices[3];
} sLib3MFTriangle;

typedef struct {
    Lib3MF_uint32 m_ResourceID;
    Lib3MF_uint32 m_PropertyIDs[3];
} sLib3MFTriangleProperties;

typedef struct {
    Lib3MF_single m_Coordinates[3];
} sLib3MFPosition;

typedef struct {
    Lib3MF_single m_Coordinates[2];
} sLib3MFPosition2D;

typedef struct {
    Lib3MF_uint32 m_PropertyID;
    Lib3MF_double m_MixingRatio;
} sLib3MFCompositeConstituent;

typedef struct {
    Lib3MF_uint32 m_ResourceID;
    structEnumLib3MFBlendMethod m_TheBlendMethod;
} sLib3MFMultiPropertyLayer;

typedef struct {
    Lib3MF_double m_U;
    Lib3MF_double m_V;
} sLib3MFTex2Coord;

typedef struct {
    Lib3MF_single m_Fields[4][3];
} sLib3MFTransform;

typedef struct {
    Lib3MF_single m_MinCoordinate[3];
    Lib3MF_single m_MaxCoordinate[3];
} sLib3MFBox;

typedef struct {
    Lib3MF_uint8 m_Red;
    Lib3MF_uint8 m_Green;
    Lib3MF_uint8 m_Blue;
    Lib3MF_uint8 m_Alpha;
} sLib3MFColor;

typedef struct {
    Lib3MF_uint32 m_Indices[2];
    Lib3MF_double m_Radii[2];
    structEnumLib3MFBeamLatticeCapMode m_CapModes[2];
} sLib3MFBeam;

typedef struct {
    Lib3MF_uint32 m_Index;
    Lib3MF_double m_Radius;
} sLib3MFBall;

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
