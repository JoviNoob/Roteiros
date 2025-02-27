// ConsoleApplication1.cpp : define o ponto de entrada para o aplicativo do console.
//


#include "stdafx.h"
#include <iostream>


extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#define AV_OUTPUT_FILE "udp://127.0.0.1:8000"
#define AV_OUTPUT_FORMAT "mpegts"
#define AV_OUTPUT_BITRATE 200000
#define AV_FRAMERATE 24
#define AV_OUTPUT_CODEC "mpeg1video"

#pragma warning(disable : 4996)

using namespace std;

typedef struct {
	AVFormatContext *formatCtx;
	AVCodecContext 	*codecCtx;
	AVCodec 		*encoder;
	AVCodec 		*audioencoder;
	AVCodecContext  *audiocodecCtx;
	AVFrame 		*frame;
	AVPacket 		packet;
} ff_input_t;

//FFMPEG output env
typedef struct {
	AVFormatContext *formatCtx;
	AVCodecContext  *codecCtx;
	AVCodec 		*encoder;
	AVStream 		*outStream;
	AVFrame  		*frame;
	AVProgram 		*program;
	AVPacket 		packet;
} ff_output_t;

int main()
{
	ff_input_t input_t;
	ff_output_t output_t;
	int i, gotPacket;

	av_register_all();
	avformat_network_init();
	input_t.formatCtx = avformat_alloc_context();

	if (avformat_open_input(&input_t.formatCtx, "C:\\teste.mpeg", NULL, NULL) != 0)
		return 0;



	if (!(avformat_find_stream_info(input_t.formatCtx, NULL) >= 0)) {
		return -1;
	}

	int videoStreamIndex = av_find_best_stream(input_t.formatCtx, AVMEDIA_TYPE_VIDEO, -1, -1, &input_t.encoder, 0);
	int audioStreamIndex = av_find_best_stream(input_t.formatCtx, AVMEDIA_TYPE_AUDIO, -1, -1, &input_t.audioencoder, 0);

	//input_t.codecPrs = input_t.formatCtx->streams[videoStreamIndex]->codecpar;


	av_dump_format(input_t.formatCtx, 0, "C:\\teste.mpeg", 0);

	//cout << "valor de i : " << i << endl;

	if (videoStreamIndex < 0 || audioStreamIndex < 0)
		return -2;

	cout << "VIDEO ST: " << videoStreamIndex << " AUDIO ST: " << audioStreamIndex << "\n";

	output_t.formatCtx = input_t.formatCtx;

	//av_packet_rescale_ts(&output_t.packet, output_t.codecCtx->time_base, output_t.formatCtx->streams[videoStreamIndex]->time_base);



	if (avformat_alloc_output_context2(&output_t.formatCtx, input_t.formatCtx->oformat, AV_OUTPUT_FORMAT, AV_OUTPUT_FILE) < 0)
		return -3;

	output_t.formatCtx->iformat = NULL;
	av_dump_format(output_t.formatCtx, 0, AV_OUTPUT_FILE, 1);

	system("PAUSE");

	return 0;
}