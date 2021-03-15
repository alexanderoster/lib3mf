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

Abstract: This is an autogenerated C++-Header file with basic types in
order to allow an easy use of the 3MF Library

Interface version: 2.2.0

*/

#ifndef __LIB3MF_TYPES_HEADER_CPP
#define __LIB3MF_TYPES_HEADER_CPP


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
#define LIB3MF_VERSION_MINOR 2
#define LIB3MF_VERSION_MICRO 0
#define LIB3MF_VERSION_PRERELEASEINFO "develop"
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
typedef Lib3MFHandle Lib3MF_MetaData;
typedef Lib3MFHandle Lib3MF_MetaDataGroup;
typedef Lib3MFHandle Lib3MF_Object;
typedef Lib3MFHandle Lib3MF_MeshObject;
typedef Lib3MFHandle Lib3MF_BeamLattice;
typedef Lib3MFHandle Lib3MF_Component;
typedef Lib3MFHandle Lib3MF_ComponentsObject;
typedef Lib3MFHandle Lib3MF_BeamSet;
typedef Lib3MFHandle Lib3MF_BaseMaterialGroup;
typedef Lib3MFHandle Lib3MF_ColorGroup;
typedef Lib3MFHandle Lib3MF_Texture2DGroup;
typedef Lib3MFHandle Lib3MF_CompositeMaterials;
typedef Lib3MFHandle Lib3MF_MultiPropertyGroup;
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

namespace Lib3MF {

  /*************************************************************************************************************************
   Declaration of enums
  **************************************************************************************************************************/
  
  enum class ePropertyType : Lib3MF_int32 {
    NoPropertyType = 0,
    BaseMaterial = 1,
    TexCoord = 2,
    Colors = 3,
    Composite = 4,
    Multi = 5
  };
  
  enum class eSlicesMeshResolution : Lib3MF_int32 {
    Fullres = 0,
    Lowres = 1
  };
  
  enum class eModelUnit : Lib3MF_int32 {
    MicroMeter = 0,
    MilliMeter = 1,
    CentiMeter = 2,
    Inch = 3,
    Foot = 4,
    Meter = 5
  };
  
  enum class eObjectType : Lib3MF_int32 {
    Other = 0,
    Model = 1,
    Support = 2,
    SolidSupport = 3
  };
  
  enum class eTextureType : Lib3MF_int32 {
    Unknown = 0,
    PNG = 1,
    JPEG = 2
  };
  
  enum class eTextureTileStyle : Lib3MF_int32 {
    Wrap = 0,
    Mirror = 1,
    Clamp = 2,
    NoTileStyle = 3
  };
  
  enum class eTextureFilter : Lib3MF_int32 {
    Auto = 0,
    Linear = 1,
    Nearest = 2
  };
  
  enum class eBeamLatticeCapMode : Lib3MF_int32 {
    Sphere = 0,
    HemiSphere = 1,
    Butt = 2
  };
  
  enum class eBeamLatticeClipMode : Lib3MF_int32 {
    NoClipMode = 0,
    Inside = 1,
    Outside = 2
  };
  
  enum class eBeamLatticeBallMode : Lib3MF_int32 {
    None = 0,
    Mixed = 1,
    All = 2
  };
  
  enum class eProgressIdentifier : Lib3MF_int32 {
    QUERYCANCELED = 0,
    DONE = 1,
    CLEANUP = 2,
    READSTREAM = 3,
    EXTRACTOPCPACKAGE = 4,
    READNONROOTMODELS = 5,
    READROOTMODEL = 6,
    READRESOURCES = 7,
    READMESH = 8,
    READSLICES = 9,
    READBUILD = 10,
    READCUSTOMATTACHMENT = 11,
    READTEXTURETACHMENTS = 12,
    CREATEOPCPACKAGE = 13,
    WRITEMODELSTOSTREAM = 14,
    WRITEROOTMODEL = 15,
    WRITENONROOTMODELS = 16,
    WRITEATTACHMENTS = 17,
    WRITECONTENTTYPES = 18,
    WRITENOBJECTS = 19,
    WRITENODES = 20,
    WRITETRIANGLES = 21,
    WRITESLICES = 22,
    WRITEKEYSTORE = 23
  };
  
  enum class eBlendMethod : Lib3MF_int32 {
    NoBlendMethod = 0,
    Mix = 1,
    Multiply = 2
  };
  
  enum class eEncryptionAlgorithm : Lib3MF_int32 {
    AES256_GCM = 1
  };
  
  enum class eWrappingAlgorithm : Lib3MF_int32 {
    RSA_OAEP = 0
  };
  
  enum class eMgfAlgorithm : Lib3MF_int32 {
    MGF1_SHA1 = 160,
    MGF1_SHA224 = 224,
    MGF1_SHA256 = 256,
    MGF1_SHA384 = 384,
    MGF1_SHA512 = 512
  };
  
  enum class eDigestMethod : Lib3MF_int32 {
    SHA1 = 160,
    SHA256 = 256
  };
  
  enum class eCompression : Lib3MF_int32 {
    NoCompression = 0,
    Deflate = 1
  };
  
  /*************************************************************************************************************************
   Declaration of structs
  **************************************************************************************************************************/
  
  #pragma pack (1)
  
  typedef struct {
      Lib3MF_uint32 m_Indices[3];
  } sTriangle;
  
  typedef struct {
      Lib3MF_uint32 m_ResourceID;
      Lib3MF_uint32 m_PropertyIDs[3];
  } sTriangleProperties;
  
  typedef struct {
      Lib3MF_single m_Coordinates[3];
  } sPosition;
  
  typedef struct {
      Lib3MF_single m_Coordinates[2];
  } sPosition2D;
  
  typedef struct {
      Lib3MF_uint32 m_PropertyID;
      Lib3MF_double m_MixingRatio;
  } sCompositeConstituent;
  
  typedef struct {
      Lib3MF_uint32 m_ResourceID;
      eBlendMethod m_TheBlendMethod;
  } sMultiPropertyLayer;
  
  typedef struct {
      Lib3MF_double m_U;
      Lib3MF_double m_V;
  } sTex2Coord;
  
  typedef struct {
      Lib3MF_single m_Fields[4][3];
  } sTransform;
  
  typedef struct {
      Lib3MF_single m_MinCoordinate[3];
      Lib3MF_single m_MaxCoordinate[3];
  } sBox;
  
  typedef struct {
      Lib3MF_uint8 m_Red;
      Lib3MF_uint8 m_Green;
      Lib3MF_uint8 m_Blue;
      Lib3MF_uint8 m_Alpha;
  } sColor;
  
  typedef struct {
      Lib3MF_uint32 m_Indices[2];
      Lib3MF_double m_Radii[2];
      eBeamLatticeCapMode m_CapModes[2];
  } sBeam;
  
  typedef struct {
      Lib3MF_uint32 m_Index;
      Lib3MF_double m_Radius;
  } sBall;
  
  #pragma pack ()
  
  /*************************************************************************************************************************
   Declaration of function pointers 
  **************************************************************************************************************************/
  
  /**
  * ProgressCallback - A callback function
  *
  * @param[out] pAbort - Returns whether the calculation should be aborted
  * @param[in] dProgressValue - The value of the progress function: values in the interval [0,1] are progress; < mean no progress update
  * @param[in] eProgressIdentifier - An identifier of progress
  * @param[in] pUserData - Userdata that is passed to the callback function
  */
  typedef void(*ProgressCallback)(bool *, Lib3MF_double, Lib3MF::eProgressIdentifier, Lib3MF_pvoid);
  
  /**
  * WriteCallback - Callback to call for writing a data chunk
  *
  * @param[in] nByteData - Pointer to the data to be written
  * @param[in] nNumBytes - Number of bytes to write
  * @param[in] pUserData - Userdata that is passed to the callback function
  */
  typedef void(*WriteCallback)(Lib3MF_uint64, Lib3MF_uint64, Lib3MF_pvoid);
  
  /**
  * ReadCallback - Callback to call for reading a data chunk
  *
  * @param[in] nByteData - Pointer to a buffer to read data into
  * @param[in] nNumBytes - Number of bytes to read
  * @param[in] pUserData - Userdata that is passed to the callback function
  */
  typedef void(*ReadCallback)(Lib3MF_uint64, Lib3MF_uint64, Lib3MF_pvoid);
  
  /**
  * SeekCallback - Callback to call for seeking in the stream
  *
  * @param[in] nPosition - Position in the stream to move to
  * @param[in] pUserData - Userdata that is passed to the callback function
  */
  typedef void(*SeekCallback)(Lib3MF_uint64, Lib3MF_pvoid);
  
  /**
  * RandomNumberCallback - Callback to generate random numbers
  *
  * @param[in] nByteData - Pointer to a buffer to read data into
  * @param[in] nNumBytes - Size of available bytes in the buffer
  * @param[in] pUserData - Userdata that is passed to the callback function
  * @param[out] pBytesWritten - Number of bytes generated when succeed. 0 or less if failed.
  */
  typedef void(*RandomNumberCallback)(Lib3MF_uint64, Lib3MF_uint64, Lib3MF_pvoid, Lib3MF_uint64 *);
  
  /**
  * KeyWrappingCallback - A callback used to wrap (encrypt) the content key available in keystore resource group
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
  typedef void(*KeyWrappingCallback)(Lib3MF_AccessRight, Lib3MF_uint64, const Lib3MF_uint8 *, const Lib3MF_uint64, Lib3MF_uint64*, Lib3MF_uint8 *, Lib3MF_pvoid, Lib3MF_uint64 *);
  
  /**
  * ContentEncryptionCallback - A callback to encrypt/decrypt content called on each resource encrypted. This might be called several times depending on content size. If Input is not available(either null or size is 0), clients must return the result of authenticated tag generation/validation.
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
  typedef void(*ContentEncryptionCallback)(Lib3MF_ContentEncryptionParams, Lib3MF_uint64, const Lib3MF_uint8 *, const Lib3MF_uint64, Lib3MF_uint64*, Lib3MF_uint8 *, Lib3MF_pvoid, Lib3MF_uint64 *);
  
} // namespace Lib3MF;

// define legacy C-names for enums, structs and function types
typedef Lib3MF::ePropertyType eLib3MFPropertyType;
typedef Lib3MF::eSlicesMeshResolution eLib3MFSlicesMeshResolution;
typedef Lib3MF::eModelUnit eLib3MFModelUnit;
typedef Lib3MF::eObjectType eLib3MFObjectType;
typedef Lib3MF::eTextureType eLib3MFTextureType;
typedef Lib3MF::eTextureTileStyle eLib3MFTextureTileStyle;
typedef Lib3MF::eTextureFilter eLib3MFTextureFilter;
typedef Lib3MF::eBeamLatticeCapMode eLib3MFBeamLatticeCapMode;
typedef Lib3MF::eBeamLatticeClipMode eLib3MFBeamLatticeClipMode;
typedef Lib3MF::eBeamLatticeBallMode eLib3MFBeamLatticeBallMode;
typedef Lib3MF::eProgressIdentifier eLib3MFProgressIdentifier;
typedef Lib3MF::eBlendMethod eLib3MFBlendMethod;
typedef Lib3MF::eEncryptionAlgorithm eLib3MFEncryptionAlgorithm;
typedef Lib3MF::eWrappingAlgorithm eLib3MFWrappingAlgorithm;
typedef Lib3MF::eMgfAlgorithm eLib3MFMgfAlgorithm;
typedef Lib3MF::eDigestMethod eLib3MFDigestMethod;
typedef Lib3MF::eCompression eLib3MFCompression;
typedef Lib3MF::sTriangle sLib3MFTriangle;
typedef Lib3MF::sTriangleProperties sLib3MFTriangleProperties;
typedef Lib3MF::sPosition sLib3MFPosition;
typedef Lib3MF::sPosition2D sLib3MFPosition2D;
typedef Lib3MF::sCompositeConstituent sLib3MFCompositeConstituent;
typedef Lib3MF::sMultiPropertyLayer sLib3MFMultiPropertyLayer;
typedef Lib3MF::sTex2Coord sLib3MFTex2Coord;
typedef Lib3MF::sTransform sLib3MFTransform;
typedef Lib3MF::sBox sLib3MFBox;
typedef Lib3MF::sColor sLib3MFColor;
typedef Lib3MF::sBeam sLib3MFBeam;
typedef Lib3MF::sBall sLib3MFBall;
typedef Lib3MF::ProgressCallback Lib3MFProgressCallback;
typedef Lib3MF::WriteCallback Lib3MFWriteCallback;
typedef Lib3MF::ReadCallback Lib3MFReadCallback;
typedef Lib3MF::SeekCallback Lib3MFSeekCallback;
typedef Lib3MF::RandomNumberCallback Lib3MFRandomNumberCallback;
typedef Lib3MF::KeyWrappingCallback Lib3MFKeyWrappingCallback;
typedef Lib3MF::ContentEncryptionCallback Lib3MFContentEncryptionCallback;

#endif // __LIB3MF_TYPES_HEADER_CPP
