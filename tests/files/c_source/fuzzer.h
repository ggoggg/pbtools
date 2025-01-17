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

#ifndef FUZZER_H
#define FUZZER_H

#include "pbtools.h"

/**
 * Enum fuzzer.Everything.NestedEnum.
 */
enum fuzzer_everything_nested_enum_e {
    fuzzer_everything_nested_enum_zero_e = 0,
    fuzzer_everything_nested_enum_foo_e = 1,
    fuzzer_everything_nested_enum_bar_e = 2,
    fuzzer_everything_nested_enum_baz_e = 3,
    fuzzer_everything_nested_enum_neg_e = -1
};

/**
 * Enum fuzzer.Everything.NestedMessage.oneof_field.
 */
enum fuzzer_everything_nested_message_oneof_field_choice_e {
    fuzzer_everything_nested_message_oneof_field_choice_none_e = 0,
    fuzzer_everything_nested_message_oneof_field_choice_a_e = 1,
    fuzzer_everything_nested_message_oneof_field_choice_b_e = 2,
    fuzzer_everything_nested_message_oneof_field_choice_c_e = 3
};

/**
 * Oneof fuzzer.Everything.NestedMessage.oneof_field.
 */
struct fuzzer_everything_nested_message_oneof_field_oneof_t {
    enum fuzzer_everything_nested_message_oneof_field_choice_e choice;
    union {
        int32_t a;
        char *b_p;
        float c;
    } value;
};

/**
 * Message fuzzer.Everything.NestedMessage.
 */
struct fuzzer_everything_nested_message_repeated_t {
    int length;
    struct fuzzer_everything_nested_message_t **items_pp;
    struct fuzzer_everything_nested_message_t *head_p;
    struct fuzzer_everything_nested_message_t *tail_p;
};

struct fuzzer_everything_nested_message_t {
    struct pbtools_message_base_t base;
    struct fuzzer_everything_nested_message_oneof_field_oneof_t oneof_field;
};

/**
 * Enum fuzzer.Everything.oneof_field.
 */
enum fuzzer_everything_oneof_field_choice_e {
    fuzzer_everything_oneof_field_choice_none_e = 0,
    fuzzer_everything_oneof_field_choice_oneof_uint32_e = 1,
    fuzzer_everything_oneof_field_choice_oneof_nested_message_e = 2,
    fuzzer_everything_oneof_field_choice_oneof_string_e = 3,
    fuzzer_everything_oneof_field_choice_oneof_bytes_e = 4
};

/**
 * Oneof fuzzer.Everything.oneof_field.
 */
struct fuzzer_everything_oneof_field_oneof_t {
    enum fuzzer_everything_oneof_field_choice_e choice;
    union {
        uint32_t oneof_uint32;
        struct fuzzer_everything_nested_message_t oneof_nested_message;
        char *oneof_string_p;
        struct pbtools_bytes_t oneof_bytes;
    } value;
};

/**
 * Message fuzzer.Everything.
 */
struct fuzzer_everything_repeated_t {
    int length;
    struct fuzzer_everything_t **items_pp;
    struct fuzzer_everything_t *head_p;
    struct fuzzer_everything_t *tail_p;
};

struct fuzzer_everything_t {
    struct pbtools_message_base_t base;
    int32_t optional_int32;
    int64_t optional_int64;
    uint32_t optional_uint32;
    uint64_t optional_uint64;
    int32_t optional_sint32;
    int64_t optional_sint64;
    uint32_t optional_fixed32;
    uint64_t optional_fixed64;
    int32_t optional_sfixed32;
    int64_t optional_sfixed64;
    float optional_float;
    double optional_double;
    bool optional_bool;
    char *optional_string_p;
    struct pbtools_bytes_t optional_bytes;
    struct fuzzer_everything_nested_message_t optional_nested_message;
    enum fuzzer_everything_nested_enum_e optional_nested_enum;
    char *optional_string_piece_p;
    char *optional_cord_p;
    struct fuzzer_everything_nested_message_t optional_lazy_message;
    struct pbtools_repeated_int32_t repeated_int32;
    struct pbtools_repeated_int64_t repeated_int64;
    struct pbtools_repeated_uint32_t repeated_uint32;
    struct pbtools_repeated_uint64_t repeated_uint64;
    struct pbtools_repeated_int32_t repeated_sint32;
    struct pbtools_repeated_int64_t repeated_sint64;
    struct pbtools_repeated_uint32_t repeated_fixed32;
    struct pbtools_repeated_uint64_t repeated_fixed64;
    struct pbtools_repeated_int32_t repeated_sfixed32;
    struct pbtools_repeated_int64_t repeated_sfixed64;
    struct pbtools_repeated_float_t repeated_float;
    struct pbtools_repeated_double_t repeated_double;
    struct pbtools_repeated_bool_t repeated_bool;
    struct pbtools_repeated_string_t repeated_string;
    struct pbtools_repeated_bytes_t repeated_bytes;
    struct fuzzer_everything_nested_message_repeated_t repeated_nested_message;
    struct pbtools_repeated_int32_t repeated_nested_enum;
    struct pbtools_repeated_string_t repeated_string_piece;
    struct pbtools_repeated_string_t repeated_cord;
    struct fuzzer_everything_nested_message_repeated_t repeated_lazy_message;
    struct fuzzer_everything_oneof_field_oneof_t oneof_field;
};

int fuzzer_everything_repeated_int32_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_int64_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_uint32_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_uint64_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_sint32_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_sint64_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_fixed32_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_fixed64_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_sfixed32_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_sfixed64_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_float_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_double_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_bool_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_string_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_bytes_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_nested_message_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_nested_enum_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_string_piece_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_cord_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

int fuzzer_everything_repeated_lazy_message_alloc(
    struct fuzzer_everything_t *self_p,
    int length);

void fuzzer_everything_nested_message_oneof_field_a_init(
    struct fuzzer_everything_nested_message_t *self_p);

void fuzzer_everything_nested_message_oneof_field_b_init(
    struct fuzzer_everything_nested_message_t *self_p);

void fuzzer_everything_nested_message_oneof_field_c_init(
    struct fuzzer_everything_nested_message_t *self_p);

void fuzzer_everything_oneof_field_oneof_uint32_init(
    struct fuzzer_everything_t *self_p);

void fuzzer_everything_oneof_field_oneof_nested_message_init(
    struct fuzzer_everything_t *self_p);

void fuzzer_everything_oneof_field_oneof_string_init(
    struct fuzzer_everything_t *self_p);

void fuzzer_everything_oneof_field_oneof_bytes_init(
    struct fuzzer_everything_t *self_p);

/**
 * Encoding and decoding of fuzzer.Everything.
 */
struct fuzzer_everything_t *
fuzzer_everything_new(
    void *workspace_p,
    size_t size);

int fuzzer_everything_encode(
    struct fuzzer_everything_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int fuzzer_everything_decode(
    struct fuzzer_everything_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void fuzzer_everything_init(
    struct fuzzer_everything_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct fuzzer_everything_t *next_p);

void fuzzer_everything_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct fuzzer_everything_t *self_p);

void fuzzer_everything_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_t *self_p);

void fuzzer_everything_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct fuzzer_everything_repeated_t *repeated_p);

void fuzzer_everything_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_repeated_t *repeated_p);

void fuzzer_everything_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_repeated_t *repeated_p);

void fuzzer_everything_nested_message_init(
    struct fuzzer_everything_nested_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct fuzzer_everything_nested_message_t *next_p);

void fuzzer_everything_nested_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct fuzzer_everything_nested_message_t *self_p);

void fuzzer_everything_nested_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_nested_message_t *self_p);

void fuzzer_everything_nested_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct fuzzer_everything_nested_message_repeated_t *repeated_p);

void fuzzer_everything_nested_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_nested_message_repeated_t *repeated_p);

void fuzzer_everything_nested_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_nested_message_repeated_t *repeated_p);

#endif
