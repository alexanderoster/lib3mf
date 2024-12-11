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

Abstract: This is the class declaration of CBeamLattice

*/


#ifndef __LIB3MF_BEAMLATTICE
#define __LIB3MF_BEAMLATTICE

#include "lib3mf_interfaces.hpp"

// Parent classes
#include "lib3mf_base.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#endif

// Include custom headers here.


namespace Lib3MF {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CBeamLattice 
**************************************************************************************************************************/

class CBeamLattice : public virtual IBeamLattice, public virtual CBase {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	Lib3MF_double GetMinLength() override;

	void SetMinLength(const Lib3MF_double dMinLength) override;

	void GetClipping(Lib3MF::eBeamLatticeClipMode & eClipMode, Lib3MF_uint32 & nUniqueResourceID) override;

	void SetClipping(const Lib3MF::eBeamLatticeClipMode eClipMode, const Lib3MF_uint32 nUniqueResourceID) override;

	bool GetRepresentation(Lib3MF_uint32 & nUniqueResourceID) override;

	void SetRepresentation(const Lib3MF_uint32 nUniqueResourceID) override;

	void GetBallOptions(Lib3MF::eBeamLatticeBallMode & eBallMode, Lib3MF_double & dBallRadius) override;

	void SetBallOptions(const Lib3MF::eBeamLatticeBallMode eBallMode, const Lib3MF_double dBallRadius) override;

	Lib3MF_uint32 GetBeamCount() override;

	Lib3MF::sBeam GetBeam(const Lib3MF_uint32 nIndex) override;

	Lib3MF_uint32 AddBeam(const Lib3MF::sBeam BeamInfo) override;

	void SetBeam(const Lib3MF_uint32 nIndex, const Lib3MF::sBeam BeamInfo) override;

	void SetBeams(const Lib3MF_uint64 nBeamInfoBufferSize, const Lib3MF::sBeam * pBeamInfoBuffer) override;

	void GetBeams(Lib3MF_uint64 nBeamInfoBufferSize, Lib3MF_uint64* pBeamInfoNeededCount, Lib3MF::sBeam * pBeamInfoBuffer) override;

	Lib3MF_uint32 GetBallCount() override;

	Lib3MF::sBall GetBall(const Lib3MF_uint32 nIndex) override;

	Lib3MF_uint32 AddBall(const Lib3MF::sBall BallInfo) override;

	void SetBall(const Lib3MF_uint32 nIndex, const Lib3MF::sBall BallInfo) override;

	void SetBalls(const Lib3MF_uint64 nBallInfoBufferSize, const Lib3MF::sBall * pBallInfoBuffer) override;

	void GetBalls(Lib3MF_uint64 nBallInfoBufferSize, Lib3MF_uint64* pBallInfoNeededCount, Lib3MF::sBall * pBallInfoBuffer) override;

	Lib3MF_uint32 GetBeamSetCount() override;

	IBeamSet * AddBeamSet() override;

	IBeamSet * GetBeamSet(const Lib3MF_uint32 nIndex) override;

};

} // namespace Impl
} // namespace Lib3MF

#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif // __LIB3MF_BEAMLATTICE
