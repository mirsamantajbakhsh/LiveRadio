#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include "liblame/lame.h" 

static lame_global_flags *glf = NULL;

void Java_ir_mstajbakhsh_liveaudio_Lame_init(
		JNIEnv *env, jclass cls, jint inSamplerate, jint outChannel,
		jint outSamplerate, jint outBitrate, jint quality) {
	if (glf != NULL) {
		lame_close(glf);
		glf = NULL;
	}
	glf = lame_init();
	lame_set_in_samplerate(glf, inSamplerate);
	lame_set_num_channels(glf, outChannel);
	lame_set_out_samplerate(glf, outSamplerate);
	lame_set_brate(glf, outBitrate);
	lame_set_quality(glf, quality);
	lame_init_params(glf);
}

jint Java_ir_mstajbakhsh_liveaudio_Lame_encode(
		JNIEnv *env, jclass cls, jshortArray buffer_l, jshortArray buffer_r,
		jint samples, jbyteArray mp3buf) {
	jshort* j_buffer_l = (*env)->GetShortArrayElements(env, buffer_l, NULL);

	jshort* j_buffer_r = (*env)->GetShortArrayElements(env, buffer_r, NULL);

	const jsize mp3buf_size = (*env)->GetArrayLength(env, mp3buf);
	jbyte* j_mp3buf = (*env)->GetByteArrayElements(env, mp3buf, NULL);

	int result = lame_encode_buffer(glf, j_buffer_l, j_buffer_r,
			samples, j_mp3buf, mp3buf_size);

	(*env)->ReleaseShortArrayElements(env, buffer_l, j_buffer_l, 0);
	(*env)->ReleaseShortArrayElements(env, buffer_r, j_buffer_r, 0);
	(*env)->ReleaseByteArrayElements(env, mp3buf, j_mp3buf, 0);

	return result;
}

jint Java_ir_mstajbakhsh_liveaudio_Lame_flush(
		JNIEnv *env, jclass cls, jbyteArray mp3buf) {
	const jsize mp3buf_size = (*env)->GetArrayLength(env, mp3buf);
	jbyte* j_mp3buf = (*env)->GetByteArrayElements(env, mp3buf, NULL);

	int result = lame_encode_flush(glf, j_mp3buf, mp3buf_size);

	(*env)->ReleaseByteArrayElements(env, mp3buf, j_mp3buf, 0);

	return result;
}

void Java_ir_mstajbakhsh_liveaudio_Lame_close(
		JNIEnv *env, jclass cls) {
	lame_close(glf);
	glf = NULL;
}
