//WTV GUIDS
#define WTV_HEADER "\xB7\xD8\x00\x20\x37\x49\xDA\x11\xA6\x4E\x00\x07\xE9\x5E\xAD\x8D"
#define WTV_STREAM "\xED\xA4\x13\x23\x2D\xBF\x4F\x45\xAD\x8A\xD9\x5B\xA7\xF9\x1F\xEE"
#define WTV_STREAM2 "\xA2\xC3\xD2\xC2\x7E\x9A\xDA\x11\x8B\xF7\x00\x07\xE9\x5E\xAD\x8D"
#define WTV_DATA "\x95\xC3\xD2\xC2\x7E\x9A\xDA\x11\x8B\xF7\x00\x07\xE9\x5E\xAD\x8D"
#define WTV_STREAM_VIDEO "\x76\x69\x64\x73\x00\x00\x10\x00\x80\x00\x00\xAA\x00\x38\x9B\x71"
#define WTV_STREAM_AUDIO "\x61\x75\x64\x73\x00\x00\x10\x00\x80\x00\x00\xAA\x00\x38\x9B\x71"
#define WTV_STREAM_MSTVCAPTION "\x89\x8A\x8B\xB8\x49\xB0\x80\x4C\xAD\xCF\x58\x98\x98\x5E\x22\xC1"
#define WTV_EOF "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
#define WTV_TIMING "\x5B\x05\xE6\x1B\x97\xA9\x49\x43\x88\x17\x1A\x65\x5A\x29\x8A\x97"

#define WTV_CHUNK_SIZE 0x1000
#define WTV_META_CHUNK_SIZE 0x40000

#define WTV_META_CHUNK_MASK 0xfffffffffffc0000

#define WTV_TABLE_ENTRIES ".entries."

//Maximum size we will try and malloc for chunked_buffer. 100MB
#define WTV_MAX_ALLOC 1024*1024*100

#define WTV_CC_TIMESTAMP_MAGIC 1668330
#define WTV_CC_TIMESTAMP_MAGIC_THRESH 2 //Only switch to alt stream after THRESH magic numbers

struct wtv_chunked_buffer
{
	uint64_t skip_chunks[256];
	uint32_t chunk;
	uint8_t count;
	uint8_t* buffer;
	uint32_t buffer_size;
	uint64_t filepos;
};
