'''++

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

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0-develop.

Abstract: This is an autogenerated Python application that demonstrates the
 usage of the Python bindings of the 3MF Library

Interface version: 2.3.0

'''


import os
import sys
sys.path.append(os.path.join(os.path.dirname(os.path.realpath(__file__)), "..", "..", "Bindings", "Python"))
import Lib3MF


def buildTriangle(mesh):
	triangle = Lib3MF.Triangle()
	position = Lib3MF.Position()

	position.Coordinates[0] = 0
	position.Coordinates[1] = 0
	position.Coordinates[2] = 0
	triangle.Indices[0] = mesh.AddVertex(position)

	position.Coordinates[0] = 0
	position.Coordinates[1] = 1
	position.Coordinates[2] = 0
	triangle.Indices[1] = mesh.AddVertex(position)

	position.Coordinates[0] = 0
	position.Coordinates[1] = 0
	position.Coordinates[2] = 1
	triangle.Indices[2] = mesh.AddVertex(position)

	mesh.AddTriangle(triangle)

def main():
	libpath = '../../Bin' # TODO add the location of the shared library binary here
	wrapper = Lib3MF.Wrapper(os.path.join(libpath, "lib3mf"))
	
	major, minor, micro = wrapper.GetLibraryVersion()
	print("Lib3MF version: {:d}.{:d}.{:d}".format(major, minor, micro), end="")
	hasInfo, prereleaseinfo = wrapper.GetPrereleaseInformation()
	if hasInfo:
		print("-"+prereleaseinfo, end="")
	hasInfo, buildinfo = wrapper.GetBuildInformation()
	if hasInfo:
		print("+"+buildinfo, end="")
	print("")

	# this example is REALLY simplisitic, but you get the point :)
	model = wrapper.CreateModel()
	meshObject = model.AddMeshObject()
	buildTriangle(meshObject)

	writer = model.QueryWriter("3mf")
	writer.WriteToFile("triangle.3mf")

if __name__ == "__main__":
	try:
		main()
	except Lib3MF.ELib3MFException as e:
		print(e)
