/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by pbtools.
 */

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "pbtools.h"

/**
 * Enum benchmark.Enum.
 */
enum benchmark_enum_e {
    benchmark_enum_e0_e = 0,
    benchmark_enum_e1_e = 1,
    benchmark_enum_e2_e = 2,
    benchmark_enum_e3_e = 3,
    benchmark_enum_e5_e = 5
};

/**
 * Message benchmark.SubMessage.
 */
struct benchmark_sub_message_repeated_t {
    int length;
    struct benchmark_sub_message_t **items_pp;
    struct benchmark_sub_message_t *head_p;
    struct benchmark_sub_message_t *tail_p;
};

struct benchmark_sub_message_t {
    struct pbtools_message_base_t base;
    uint32_t field1;
    uint32_t field2;
    int32_t field3;
    char *field15_p;
    struct pbtools_bytes_t field12;
    int64_t field13;
    int64_t field14;
    uint64_t field21;
    int32_t field22;
    bool field206;
    uint32_t field203;
    int32_t field204;
    char *field205_p;
    uint64_t field207;
    enum benchmark_enum_e field300;
};

/**
 * Message benchmark.Message1.
 */
struct benchmark_message1_repeated_t {
    int length;
    struct benchmark_message1_t **items_pp;
    struct benchmark_message1_t *head_p;
    struct benchmark_message1_t *tail_p;
};

struct benchmark_message1_t {
    struct pbtools_message_base_t base;
    bool field80;
    bool field81;
    int32_t field2;
    int32_t field3;
    int32_t field280;
    int32_t field6;
    int64_t field22;
    struct pbtools_repeated_string_t field4;
    bool field59;
    int32_t field16;
    int32_t field150;
    int32_t field23;
    bool field24;
    int32_t field25;
    struct benchmark_sub_message_t field15;
    bool field78;
    int32_t field67;
    int32_t field68;
    int32_t field128;
    char *field129_p;
    int32_t field131;
};

/**
 * Message benchmark.Message2.
 */
struct benchmark_message2_repeated_t {
    int length;
    struct benchmark_message2_t **items_pp;
    struct benchmark_message2_t *head_p;
    struct benchmark_message2_t *tail_p;
};

struct benchmark_message2_t {
    struct pbtools_message_base_t base;
    enum benchmark_enum_e field1;
    uint64_t field2;
    int32_t field3;
    char *field4_p;
    int32_t field5;
    bool field6;
};

/**
 * Message benchmark.Message3.SubMessage.
 */
struct benchmark_message3_sub_message_repeated_t {
    int length;
    struct benchmark_message3_sub_message_t **items_pp;
    struct benchmark_message3_sub_message_t *head_p;
    struct benchmark_message3_sub_message_t *tail_p;
};

struct benchmark_message3_sub_message_t {
    struct pbtools_message_base_t base;
    int32_t field28;
    int64_t field2;
    int32_t field12;
    char *field19_p;
    int32_t field11;
};

/**
 * Message benchmark.Message3.
 */
struct benchmark_message3_repeated_t {
    int length;
    struct benchmark_message3_t **items_pp;
    struct benchmark_message3_t *head_p;
    struct benchmark_message3_t *tail_p;
};

struct benchmark_message3_t {
    struct pbtools_message_base_t base;
    struct benchmark_message3_sub_message_repeated_t field13;
};

/**
 * Enum benchmark.Message.oneof.
 */
enum benchmark_message_oneof_choice_e {
    benchmark_message_oneof_choice_none_e = 0,
    benchmark_message_oneof_choice_message1_e = 1,
    benchmark_message_oneof_choice_message2_e = 2,
    benchmark_message_oneof_choice_message3_e = 3
};

/**
 * Oneof benchmark.Message.oneof.
 */
struct benchmark_message_oneof_oneof_t {
    enum benchmark_message_oneof_choice_e choice;
    union {
        struct benchmark_message1_t message1;
        struct benchmark_message2_t message2;
        struct benchmark_message3_t message3;
    } value;
};

/**
 * Message benchmark.Message.
 */
struct benchmark_message_repeated_t {
    int length;
    struct benchmark_message_t **items_pp;
    struct benchmark_message_t *head_p;
    struct benchmark_message_t *tail_p;
};

struct benchmark_message_t {
    struct pbtools_message_base_t base;
    struct benchmark_message_oneof_oneof_t oneof;
};

/**
 * Encoding and decoding of benchmark.SubMessage.
 */
struct benchmark_sub_message_t *
benchmark_sub_message_new(
    void *workspace_p,
    size_t size);

int benchmark_sub_message_encode(
    struct benchmark_sub_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int benchmark_sub_message_decode(
    struct benchmark_sub_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int benchmark_message1_field4_alloc(
    struct benchmark_message1_t *self_p,
    int length);

/**
 * Encoding and decoding of benchmark.Message1.
 */
struct benchmark_message1_t *
benchmark_message1_new(
    void *workspace_p,
    size_t size);

int benchmark_message1_encode(
    struct benchmark_message1_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int benchmark_message1_decode(
    struct benchmark_message1_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/**
 * Encoding and decoding of benchmark.Message2.
 */
struct benchmark_message2_t *
benchmark_message2_new(
    void *workspace_p,
    size_t size);

int benchmark_message2_encode(
    struct benchmark_message2_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int benchmark_message2_decode(
    struct benchmark_message2_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int benchmark_message3_field13_alloc(
    struct benchmark_message3_t *self_p,
    int length);

/**
 * Encoding and decoding of benchmark.Message3.
 */
struct benchmark_message3_t *
benchmark_message3_new(
    void *workspace_p,
    size_t size);

int benchmark_message3_encode(
    struct benchmark_message3_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int benchmark_message3_decode(
    struct benchmark_message3_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

void benchmark_message_oneof_message1_init(
    struct benchmark_message_t *self_p);

void benchmark_message_oneof_message2_init(
    struct benchmark_message_t *self_p);

void benchmark_message_oneof_message3_init(
    struct benchmark_message_t *self_p);

/**
 * Encoding and decoding of benchmark.Message.
 */
struct benchmark_message_t *
benchmark_message_new(
    void *workspace_p,
    size_t size);

int benchmark_message_encode(
    struct benchmark_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int benchmark_message_decode(
    struct benchmark_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void benchmark_sub_message_init(
    struct benchmark_sub_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct benchmark_sub_message_t *next_p);

void benchmark_sub_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_sub_message_t *self_p);

void benchmark_sub_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_sub_message_t *self_p);

void benchmark_sub_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_sub_message_repeated_t *repeated_p);

void benchmark_sub_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_sub_message_repeated_t *repeated_p);

void benchmark_sub_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_sub_message_repeated_t *repeated_p);

void benchmark_message1_init(
    struct benchmark_message1_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct benchmark_message1_t *next_p);

void benchmark_message1_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message1_t *self_p);

void benchmark_message1_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message1_t *self_p);

void benchmark_message1_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message1_repeated_t *repeated_p);

void benchmark_message1_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message1_repeated_t *repeated_p);

void benchmark_message1_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message1_repeated_t *repeated_p);

void benchmark_message2_init(
    struct benchmark_message2_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct benchmark_message2_t *next_p);

void benchmark_message2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message2_t *self_p);

void benchmark_message2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message2_t *self_p);

void benchmark_message2_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message2_repeated_t *repeated_p);

void benchmark_message2_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message2_repeated_t *repeated_p);

void benchmark_message2_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message2_repeated_t *repeated_p);

void benchmark_message3_init(
    struct benchmark_message3_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct benchmark_message3_t *next_p);

void benchmark_message3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message3_t *self_p);

void benchmark_message3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message3_t *self_p);

void benchmark_message3_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message3_repeated_t *repeated_p);

void benchmark_message3_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message3_repeated_t *repeated_p);

void benchmark_message3_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message3_repeated_t *repeated_p);

void benchmark_message3_sub_message_init(
    struct benchmark_message3_sub_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct benchmark_message3_sub_message_t *next_p);

void benchmark_message3_sub_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message3_sub_message_t *self_p);

void benchmark_message3_sub_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message3_sub_message_t *self_p);

void benchmark_message3_sub_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message3_sub_message_repeated_t *repeated_p);

void benchmark_message3_sub_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message3_sub_message_repeated_t *repeated_p);

void benchmark_message3_sub_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message3_sub_message_repeated_t *repeated_p);

void benchmark_message_init(
    struct benchmark_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct benchmark_message_t *next_p);

void benchmark_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message_t *self_p);

void benchmark_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message_t *self_p);

void benchmark_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message_repeated_t *repeated_p);

void benchmark_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message_repeated_t *repeated_p);

void benchmark_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message_repeated_t *repeated_p);

#endif
