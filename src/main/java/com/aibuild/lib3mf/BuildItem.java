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

This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated Java file in order to allow an easy
 use of the 3MF Library

Interface version: 2.0.0

*/

package com.aibuild.lib3mf4j;

import com.sun.jna.Library;
import com.sun.jna.Memory;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import java.lang.ref.Cleaner;


import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;

public class BuildItem extends Base {

	public BuildItem(Lib3MFWrapper wrapper, Pointer handle) {
		super(wrapper, handle);
	}

	/**
	 * Retrieves the object resource associated to a build item
	 *
	 * @return returns the associated resource instance
	 * @throws Lib3MFException
	 */
	public Object getObjectResource() throws Lib3MFException {
		Pointer bufferObjectResource = new Memory(8);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getobjectresource.invokeInt(new java.lang.Object[]{mHandle, bufferObjectResource}));
		Pointer valueObjectResource = bufferObjectResource.getPointer(0);
		Object objectResource = null;
		if (valueObjectResource == Pointer.NULL) {
		  throw new Lib3MFException(Lib3MFException.LIB3MF_ERROR_INVALIDPARAM, "ObjectResource was a null pointer");
		}
		objectResource = new Object(mWrapper, valueObjectResource);
		return objectResource;
	}

	/**
	 * returns, whether a build item has a UUID and, if true, the build item's UUID
	 *
	 * @return GetUUID Result Tuple
	 * @throws Lib3MFException
	 */
	public GetUUIDResult getUUID() throws Lib3MFException {
		Pointer bufferHasUUID = new Memory(1);
		Pointer bytesNeededUUID = new Memory(4);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getuuid.invokeInt(new java.lang.Object[]{mHandle, bufferHasUUID, 0, bytesNeededUUID, null}));
		int sizeUUID = bytesNeededUUID.getInt(0);
		Pointer bufferUUID = new Memory(sizeUUID);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getuuid.invokeInt(new java.lang.Object[]{mHandle, bufferHasUUID, sizeUUID, bytesNeededUUID, bufferUUID}));
		GetUUIDResult returnTuple = new GetUUIDResult();
		returnTuple.HasUUID = bufferHasUUID.getByte(0) != 0;
		returnTuple.UUID = new String(bufferUUID.getByteArray(0, sizeUUID - 1), StandardCharsets.UTF_8);
		return returnTuple;
	}

	public static class GetUUIDResult {
		/**
		 * flag whether the build item has a UUID
		 */
		public boolean HasUUID;

		/**
		 * the UUID as string of the form 'xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxxxxxx'
		 */
		public String UUID;

	}
	/**
	 * sets the build item's UUID
	 *
	 * @param uUID the UUID as string of the form 'xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxxxxxx'
	 * @throws Lib3MFException
	 */
	public void setUUID(String uUID) throws Lib3MFException {
		byte[] bytesUUID = uUID.getBytes(StandardCharsets.UTF_8);
		Memory bufferUUID = new Memory(bytesUUID.length + 1);
		bufferUUID.write(0, bytesUUID, 0, bytesUUID.length);
		bufferUUID.setByte(bytesUUID.length, (byte)0);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_setuuid.invokeInt(new java.lang.Object[]{mHandle, bufferUUID}));
	}

	/**
	 * Retrieves the object resource id associated to a build item
	 *
	 * @return  eturns the ID of the object
	 * @throws Lib3MFException
	 */
	public int getObjectResourceID() throws Lib3MFException {
		Pointer bufferId = new Memory(4);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getobjectresourceid.invokeInt(new java.lang.Object[]{mHandle, bufferId}));
		return bufferId.getInt(0);
	}

	/**
	 * Checks, if a build item has a non-identity transformation matrix
	 *
	 * @return returns true, if the transformation matrix is not the identity
	 * @throws Lib3MFException
	 */
	public boolean hasObjectTransform() throws Lib3MFException {
		Pointer bufferHasTransform = new Memory(1);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_hasobjecttransform.invokeInt(new java.lang.Object[]{mHandle, bufferHasTransform}));
		return bufferHasTransform.getByte(0) != 0;
	}

	/**
	 * Retrieves a build item's transformation matrix.
	 *
	 * @return returns the transformation matrix
	 * @throws Lib3MFException
	 */
	public Transform getObjectTransform() throws Lib3MFException {
		Pointer bufferTransform = new Memory(Transform.SIZE);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getobjecttransform.invokeInt(new java.lang.Object[]{mHandle, bufferTransform}));
		Transform transform = new Transform();
		transform.readFromPointer(bufferTransform, 0);
		return transform;
	}

	/**
	 * Sets a build item's transformation matrix.
	 *
	 * @param transform new transformation matrix
	 * @throws Lib3MFException
	 */
	public void setObjectTransform(Transform transform) throws Lib3MFException {
		Pointer bufferTransform = new Memory(Transform.SIZE);
		transform.writeToPointer(bufferTransform, 0);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_setobjecttransform.invokeInt(new java.lang.Object[]{mHandle, bufferTransform}));
	}

	/**
	 * Retrieves a build item's part number string
	 *
	 * @return Returns a build item's part number string
	 * @throws Lib3MFException
	 */
	public String getPartNumber() throws Lib3MFException {
		Pointer bytesNeededPartNumber = new Memory(4);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getpartnumber.invokeInt(new java.lang.Object[]{mHandle, 0, bytesNeededPartNumber, null}));
		int sizePartNumber = bytesNeededPartNumber.getInt(0);
		Pointer bufferPartNumber = new Memory(sizePartNumber);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getpartnumber.invokeInt(new java.lang.Object[]{mHandle, sizePartNumber, bytesNeededPartNumber, bufferPartNumber}));
		return new String(bufferPartNumber.getByteArray(0, sizePartNumber - 1), StandardCharsets.UTF_8);
	}

	/**
	 * Sets a build item's part number string
	 *
	 * @param setPartnumber new part number string for referencing parts from the outside world
	 * @throws Lib3MFException
	 */
	public void setPartNumber(String setPartnumber) throws Lib3MFException {
		byte[] bytesSetPartnumber = setPartnumber.getBytes(StandardCharsets.UTF_8);
		Memory bufferSetPartnumber = new Memory(bytesSetPartnumber.length + 1);
		bufferSetPartnumber.write(0, bytesSetPartnumber, 0, bytesSetPartnumber.length);
		bufferSetPartnumber.setByte(bytesSetPartnumber.length, (byte)0);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_setpartnumber.invokeInt(new java.lang.Object[]{mHandle, bufferSetPartnumber}));
	}

	/**
	 * Returns the metadatagroup of this build item
	 *
	 * @return returns an Instance of the metadatagroup of this build item
	 * @throws Lib3MFException
	 */
	public MetaDataGroup getMetaDataGroup() throws Lib3MFException {
		Pointer bufferMetaDataGroup = new Memory(8);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getmetadatagroup.invokeInt(new java.lang.Object[]{mHandle, bufferMetaDataGroup}));
		Pointer valueMetaDataGroup = bufferMetaDataGroup.getPointer(0);
		MetaDataGroup metaDataGroup = null;
		if (valueMetaDataGroup == Pointer.NULL) {
		  throw new Lib3MFException(Lib3MFException.LIB3MF_ERROR_INVALIDPARAM, "MetaDataGroup was a null pointer");
		}
		metaDataGroup = new MetaDataGroup(mWrapper, valueMetaDataGroup);
		return metaDataGroup;
	}

	/**
	 * Returns the outbox of a build item
	 *
	 * @return Outbox of this build item
	 * @throws Lib3MFException
	 */
	public Box getOutbox() throws Lib3MFException {
		Pointer bufferOutbox = new Memory(Box.SIZE);
		mWrapper.checkError(this, mWrapper.lib3mf_builditem_getoutbox.invokeInt(new java.lang.Object[]{mHandle, bufferOutbox}));
		Box outbox = new Box();
		outbox.readFromPointer(bufferOutbox, 0);
		return outbox;
	}


}

