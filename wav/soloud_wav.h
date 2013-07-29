/*
SoLoud audio engine
Copyright (c) 2013 Jari Komppa

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

#ifndef SOLOUD_WAV_H
#define SOLOUD_WAV_H

#include "soloud.h"

namespace SoLoud
{
	class Wav;

	class WavProducer : public AudioProducer
	{
		Wav *mParent;
		int mOffset;
	public:
		WavProducer(Wav *aParent);
		virtual void getAudio(float *aBuffer, int aSamples);
		virtual int hasEnded();
	};

	class Wav : public AudioFactory
	{
		void loadwav(FILE * fp, int aStereo, int aChannel);
		void loadogg(FILE * fp, int aStereo, int aChannel);
	public:
		float *mData;
		int mSampleCount;

		Wav();
		virtual ~Wav();
		void load(const char *aFilename, int aStereo = 1, int aChannel = 0);
		virtual AudioProducer *createProducer();
	};
};

#endif