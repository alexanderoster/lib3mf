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

import com.sun.jna.Memory;
import com.sun.jna.Pointer;

import java.util.Arrays;
import java.util.List;

public class Beam {

	public int[] Indices = new int[2];

	public double[] Radii = new double[2];

	public int[] CapModes = new int[2];

	public static final int SIZE = 32;

	public void readFromPointer(Pointer p, long offset) {
		Indices[0] = p.getInt(offset + 0);
		Indices[1] = p.getInt(offset + 4);
		Radii[0] = p.getDouble(offset + 8);
		Radii[1] = p.getDouble(offset + 16);
		CapModes[0] = p.getInt(offset + 24);
		CapModes[1] = p.getInt(offset + 28);
	}

	public void writeToPointer(Pointer p, long offset) {
		p.setInt(offset + 0, Indices[0]);
		p.setInt(offset + 4, Indices[1]);
		p.setDouble(offset + 8, Radii[0]);
		p.setDouble(offset + 16, Radii[1]);
		p.setInt(offset + 24, CapModes[0]);
		p.setInt(offset + 28, CapModes[1]);
	}

}

