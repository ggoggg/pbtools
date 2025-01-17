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

#ifndef REPEATED_H
#define REPEATED_H

#include "pbtools.h"

/**
 * Enum repeated.Enum.
 */
enum repeated_enum_e {
    repeated_enum_a_e = 0,
    repeated_enum_b_e = 1
};

/**
 * Message repeated.Message.
 */
struct repeated_message_repeated_t {
    int length;
    struct repeated_message_t **items_pp;
    struct repeated_message_t *head_p;
    struct repeated_message_t *tail_p;
};

struct repeated_message_t {
    struct pbtools_message_base_t base;
    struct pbtools_repeated_int32_t int32s;
    struct repeated_message_repeated_t messages;
    struct pbtools_repeated_string_t strings;
    struct pbtools_repeated_bytes_t bytes;
};

/**
 * Message repeated.MessageScalarValueTypes.
 */
struct repeated_message_scalar_value_types_repeated_t {
    int length;
    struct repeated_message_scalar_value_types_t **items_pp;
    struct repeated_message_scalar_value_types_t *head_p;
    struct repeated_message_scalar_value_types_t *tail_p;
};

struct repeated_message_scalar_value_types_t {
    struct pbtools_message_base_t base;
    struct pbtools_repeated_int32_t int32s;
    struct pbtools_repeated_int64_t int64s;
    struct pbtools_repeated_int32_t sint32s;
    struct pbtools_repeated_int64_t sint64s;
    struct pbtools_repeated_uint32_t uint32s;
    struct pbtools_repeated_uint64_t uint64s;
    struct pbtools_repeated_uint32_t fixed32s;
    struct pbtools_repeated_uint64_t fixed64s;
    struct pbtools_repeated_int32_t sfixed32s;
    struct pbtools_repeated_int64_t sfixed64s;
    struct pbtools_repeated_float_t floats;
    struct pbtools_repeated_double_t doubles;
    struct pbtools_repeated_bool_t bools;
    struct pbtools_repeated_string_t strings;
    struct pbtools_repeated_bytes_t bytess;
};

/**
 * Message repeated.MessageScalarValueTypesPacked.
 */
struct repeated_message_scalar_value_types_packed_repeated_t {
    int length;
    struct repeated_message_scalar_value_types_packed_t **items_pp;
    struct repeated_message_scalar_value_types_packed_t *head_p;
    struct repeated_message_scalar_value_types_packed_t *tail_p;
};

struct repeated_message_scalar_value_types_packed_t {
    struct pbtools_message_base_t base;
    struct pbtools_repeated_int32_t int32s;
    struct pbtools_repeated_int64_t int64s;
    struct pbtools_repeated_int32_t sint32s;
    struct pbtools_repeated_int64_t sint64s;
    struct pbtools_repeated_uint32_t uint32s;
    struct pbtools_repeated_uint64_t uint64s;
    struct pbtools_repeated_uint32_t fixed32s;
    struct pbtools_repeated_uint64_t fixed64s;
    struct pbtools_repeated_int32_t sfixed32s;
    struct pbtools_repeated_int64_t sfixed64s;
    struct pbtools_repeated_float_t floats;
    struct pbtools_repeated_double_t doubles;
    struct pbtools_repeated_bool_t bools;
    struct pbtools_repeated_string_t strings;
    struct pbtools_repeated_bytes_t bytess;
};

/**
 * Message repeated.MessageScalarValueTypesNotPacked.
 */
struct repeated_message_scalar_value_types_not_packed_repeated_t {
    int length;
    struct repeated_message_scalar_value_types_not_packed_t **items_pp;
    struct repeated_message_scalar_value_types_not_packed_t *head_p;
    struct repeated_message_scalar_value_types_not_packed_t *tail_p;
};

struct repeated_message_scalar_value_types_not_packed_t {
    struct pbtools_message_base_t base;
    struct pbtools_repeated_int32_t int32s;
    struct pbtools_repeated_int64_t int64s;
    struct pbtools_repeated_int32_t sint32s;
    struct pbtools_repeated_int64_t sint64s;
    struct pbtools_repeated_uint32_t uint32s;
    struct pbtools_repeated_uint64_t uint64s;
    struct pbtools_repeated_uint32_t fixed32s;
    struct pbtools_repeated_uint64_t fixed64s;
    struct pbtools_repeated_int32_t sfixed32s;
    struct pbtools_repeated_int64_t sfixed64s;
    struct pbtools_repeated_float_t floats;
    struct pbtools_repeated_double_t doubles;
    struct pbtools_repeated_bool_t bools;
    struct pbtools_repeated_string_t strings;
    struct pbtools_repeated_bytes_t bytess;
};

/**
 * Message repeated.Foo.
 */
struct repeated_foo_repeated_t {
    int length;
    struct repeated_foo_t **items_pp;
    struct repeated_foo_t *head_p;
    struct repeated_foo_t *tail_p;
};

struct repeated_foo_t {
    struct pbtools_message_base_t base;
    struct repeated_message_repeated_t messages;
    struct pbtools_repeated_int32_t enums;
};

/**
 * Message repeated.Bar.Fie.
 */
struct repeated_bar_fie_repeated_t {
    int length;
    struct repeated_bar_fie_t **items_pp;
    struct repeated_bar_fie_t *head_p;
    struct repeated_bar_fie_t *tail_p;
};

struct repeated_bar_fie_t {
    struct pbtools_message_base_t base;
    struct repeated_foo_repeated_t inner_foos;
};

/**
 * Message repeated.Bar.
 */
struct repeated_bar_repeated_t {
    int length;
    struct repeated_bar_t **items_pp;
    struct repeated_bar_t *head_p;
    struct repeated_bar_t *tail_p;
};

struct repeated_bar_t {
    struct pbtools_message_base_t base;
    struct repeated_foo_repeated_t foos;
    struct repeated_bar_fie_repeated_t fies;
};

int repeated_message_int32s_alloc(
    struct repeated_message_t *self_p,
    int length);

int repeated_message_messages_alloc(
    struct repeated_message_t *self_p,
    int length);

int repeated_message_strings_alloc(
    struct repeated_message_t *self_p,
    int length);

int repeated_message_bytes_alloc(
    struct repeated_message_t *self_p,
    int length);

/**
 * Encoding and decoding of repeated.Message.
 */
struct repeated_message_t *
repeated_message_new(
    void *workspace_p,
    size_t size);

int repeated_message_encode(
    struct repeated_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int repeated_message_decode(
    struct repeated_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int repeated_message_scalar_value_types_int32s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_int64s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_sint32s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_sint64s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_uint32s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_uint64s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_fixed32s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_fixed64s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_sfixed32s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_sfixed64s_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_floats_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_doubles_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_bools_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_strings_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

int repeated_message_scalar_value_types_bytess_alloc(
    struct repeated_message_scalar_value_types_t *self_p,
    int length);

/**
 * Encoding and decoding of repeated.MessageScalarValueTypes.
 */
struct repeated_message_scalar_value_types_t *
repeated_message_scalar_value_types_new(
    void *workspace_p,
    size_t size);

int repeated_message_scalar_value_types_encode(
    struct repeated_message_scalar_value_types_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int repeated_message_scalar_value_types_decode(
    struct repeated_message_scalar_value_types_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int repeated_message_scalar_value_types_packed_int32s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_int64s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_sint32s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_sint64s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_uint32s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_uint64s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_fixed32s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_fixed64s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_sfixed32s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_sfixed64s_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_floats_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_doubles_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_bools_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_strings_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_packed_bytess_alloc(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    int length);

/**
 * Encoding and decoding of repeated.MessageScalarValueTypesPacked.
 */
struct repeated_message_scalar_value_types_packed_t *
repeated_message_scalar_value_types_packed_new(
    void *workspace_p,
    size_t size);

int repeated_message_scalar_value_types_packed_encode(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int repeated_message_scalar_value_types_packed_decode(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int repeated_message_scalar_value_types_not_packed_int32s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_int64s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_sint32s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_sint64s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_uint32s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_uint64s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_fixed32s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_fixed64s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_sfixed32s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_sfixed64s_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_floats_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_doubles_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_bools_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_strings_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

int repeated_message_scalar_value_types_not_packed_bytess_alloc(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    int length);

/**
 * Encoding and decoding of repeated.MessageScalarValueTypesNotPacked.
 */
struct repeated_message_scalar_value_types_not_packed_t *
repeated_message_scalar_value_types_not_packed_new(
    void *workspace_p,
    size_t size);

int repeated_message_scalar_value_types_not_packed_encode(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int repeated_message_scalar_value_types_not_packed_decode(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int repeated_foo_messages_alloc(
    struct repeated_foo_t *self_p,
    int length);

int repeated_foo_enums_alloc(
    struct repeated_foo_t *self_p,
    int length);

/**
 * Encoding and decoding of repeated.Foo.
 */
struct repeated_foo_t *
repeated_foo_new(
    void *workspace_p,
    size_t size);

int repeated_foo_encode(
    struct repeated_foo_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int repeated_foo_decode(
    struct repeated_foo_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int repeated_bar_foos_alloc(
    struct repeated_bar_t *self_p,
    int length);

int repeated_bar_fies_alloc(
    struct repeated_bar_t *self_p,
    int length);

int repeated_bar_fie_inner_foos_alloc(
    struct repeated_bar_fie_t *self_p,
    int length);

/**
 * Encoding and decoding of repeated.Bar.
 */
struct repeated_bar_t *
repeated_bar_new(
    void *workspace_p,
    size_t size);

int repeated_bar_encode(
    struct repeated_bar_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int repeated_bar_decode(
    struct repeated_bar_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void repeated_message_init(
    struct repeated_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_message_t *next_p);

void repeated_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_message_t *self_p);

void repeated_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_t *self_p);

void repeated_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_message_repeated_t *repeated_p);

void repeated_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_message_repeated_t *repeated_p);

void repeated_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_repeated_t *repeated_p);

void repeated_message_scalar_value_types_init(
    struct repeated_message_scalar_value_types_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_message_scalar_value_types_t *next_p);

void repeated_message_scalar_value_types_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_message_scalar_value_types_t *self_p);

void repeated_message_scalar_value_types_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_scalar_value_types_t *self_p);

void repeated_message_scalar_value_types_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_message_scalar_value_types_repeated_t *repeated_p);

void repeated_message_scalar_value_types_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_message_scalar_value_types_repeated_t *repeated_p);

void repeated_message_scalar_value_types_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_scalar_value_types_repeated_t *repeated_p);

void repeated_message_scalar_value_types_packed_init(
    struct repeated_message_scalar_value_types_packed_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_message_scalar_value_types_packed_t *next_p);

void repeated_message_scalar_value_types_packed_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_message_scalar_value_types_packed_t *self_p);

void repeated_message_scalar_value_types_packed_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_scalar_value_types_packed_t *self_p);

void repeated_message_scalar_value_types_packed_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_message_scalar_value_types_packed_repeated_t *repeated_p);

void repeated_message_scalar_value_types_packed_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_message_scalar_value_types_packed_repeated_t *repeated_p);

void repeated_message_scalar_value_types_packed_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_scalar_value_types_packed_repeated_t *repeated_p);

void repeated_message_scalar_value_types_not_packed_init(
    struct repeated_message_scalar_value_types_not_packed_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_message_scalar_value_types_not_packed_t *next_p);

void repeated_message_scalar_value_types_not_packed_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_message_scalar_value_types_not_packed_t *self_p);

void repeated_message_scalar_value_types_not_packed_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_scalar_value_types_not_packed_t *self_p);

void repeated_message_scalar_value_types_not_packed_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_message_scalar_value_types_not_packed_repeated_t *repeated_p);

void repeated_message_scalar_value_types_not_packed_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_message_scalar_value_types_not_packed_repeated_t *repeated_p);

void repeated_message_scalar_value_types_not_packed_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_scalar_value_types_not_packed_repeated_t *repeated_p);

void repeated_foo_init(
    struct repeated_foo_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_foo_t *next_p);

void repeated_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_foo_t *self_p);

void repeated_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_foo_t *self_p);

void repeated_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_foo_repeated_t *repeated_p);

void repeated_foo_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_foo_repeated_t *repeated_p);

void repeated_foo_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_foo_repeated_t *repeated_p);

void repeated_bar_init(
    struct repeated_bar_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_bar_t *next_p);

void repeated_bar_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_bar_t *self_p);

void repeated_bar_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_bar_t *self_p);

void repeated_bar_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_bar_repeated_t *repeated_p);

void repeated_bar_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_bar_repeated_t *repeated_p);

void repeated_bar_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_bar_repeated_t *repeated_p);

void repeated_bar_fie_init(
    struct repeated_bar_fie_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_bar_fie_t *next_p);

void repeated_bar_fie_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct repeated_bar_fie_t *self_p);

void repeated_bar_fie_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_bar_fie_t *self_p);

void repeated_bar_fie_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_bar_fie_repeated_t *repeated_p);

void repeated_bar_fie_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_bar_fie_repeated_t *repeated_p);

void repeated_bar_fie_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_bar_fie_repeated_t *repeated_p);

#endif
