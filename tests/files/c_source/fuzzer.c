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

#include <limits.h>
#include "fuzzer.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void fuzzer_everything_oneof_field_oneof_uint32_init(
    struct fuzzer_everything_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_oneof_field_choice_oneof_uint32_e;
    self_p->oneof_field.value.oneof_uint32 = 0;
}

void fuzzer_everything_oneof_field_oneof_nested_message_init(
    struct fuzzer_everything_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_oneof_field_choice_oneof_nested_message_e;
    fuzzer_everything_nested_message_init(
        &self_p->oneof_field.value.oneof_nested_message,
        self_p->base.heap_p,
        NULL);
}

void fuzzer_everything_oneof_field_oneof_string_init(
    struct fuzzer_everything_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_oneof_field_choice_oneof_string_e;
    self_p->oneof_field.value.oneof_string_p = "";
}

void fuzzer_everything_oneof_field_oneof_bytes_init(
    struct fuzzer_everything_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_oneof_field_choice_oneof_bytes_e;
    pbtools_bytes_init(&self_p->oneof_field.value.oneof_bytes);
}

void fuzzer_everything_oneof_field_encode(
    struct pbtools_encoder_t *encoder_p,
    struct fuzzer_everything_oneof_field_oneof_t *self_p)
{
    switch (self_p->choice) {

    case fuzzer_everything_oneof_field_choice_oneof_uint32_e:
        pbtools_encoder_write_uint32(
            encoder_p,
            111,
            self_p->value.oneof_uint32);
        break;

    case fuzzer_everything_oneof_field_choice_oneof_nested_message_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            112,
            &self_p->value.oneof_nested_message.base,
            (pbtools_message_encode_inner_t)fuzzer_everything_nested_message_encode_inner);
        break;

    case fuzzer_everything_oneof_field_choice_oneof_string_e:
        pbtools_encoder_write_string(
            encoder_p,
            113,
            self_p->value.oneof_string_p);
        break;

    case fuzzer_everything_oneof_field_choice_oneof_bytes_e:
        pbtools_encoder_write_bytes(
            encoder_p,
            114,
            &self_p->value.oneof_bytes);
        break;

    default:
        break;
    }
}

static void fuzzer_everything_oneof_field_oneof_uint32_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_t *self_p)
{
    fuzzer_everything_oneof_field_oneof_uint32_init(self_p);
    self_p->oneof_field.value.oneof_uint32 = pbtools_decoder_read_uint32(
        decoder_p,
        wire_type);
}

static void fuzzer_everything_oneof_field_oneof_nested_message_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_t *self_p)
{
    fuzzer_everything_oneof_field_oneof_nested_message_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof_field.value.oneof_nested_message.base,
        (pbtools_message_decode_inner_t)fuzzer_everything_nested_message_decode_inner);
}

static void fuzzer_everything_oneof_field_oneof_string_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_t *self_p)
{
    fuzzer_everything_oneof_field_oneof_string_init(self_p);
    pbtools_decoder_read_string(decoder_p,
                                wire_type,
                                &self_p->oneof_field.value.oneof_string_p);
}

static void fuzzer_everything_oneof_field_oneof_bytes_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_t *self_p)
{
    fuzzer_everything_oneof_field_oneof_bytes_init(self_p);
    pbtools_decoder_read_bytes(decoder_p,
                               wire_type,
                               &self_p->oneof_field.value.oneof_bytes);
}

void fuzzer_everything_nested_message_oneof_field_a_init(
    struct fuzzer_everything_nested_message_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_nested_message_oneof_field_choice_a_e;
    self_p->oneof_field.value.a = 0;
}

void fuzzer_everything_nested_message_oneof_field_b_init(
    struct fuzzer_everything_nested_message_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_nested_message_oneof_field_choice_b_e;
    self_p->oneof_field.value.b_p = "";
}

void fuzzer_everything_nested_message_oneof_field_c_init(
    struct fuzzer_everything_nested_message_t *self_p)
{
    self_p->oneof_field.choice = fuzzer_everything_nested_message_oneof_field_choice_c_e;
    self_p->oneof_field.value.c = 0;
}

void fuzzer_everything_nested_message_oneof_field_encode(
    struct pbtools_encoder_t *encoder_p,
    struct fuzzer_everything_nested_message_oneof_field_oneof_t *self_p)
{
    switch (self_p->choice) {

    case fuzzer_everything_nested_message_oneof_field_choice_a_e:
        pbtools_encoder_write_int32(
            encoder_p,
            1,
            self_p->value.a);
        break;

    case fuzzer_everything_nested_message_oneof_field_choice_b_e:
        pbtools_encoder_write_string(
            encoder_p,
            10000,
            self_p->value.b_p);
        break;

    case fuzzer_everything_nested_message_oneof_field_choice_c_e:
        pbtools_encoder_write_float(
            encoder_p,
            10001,
            self_p->value.c);
        break;

    default:
        break;
    }
}

static void fuzzer_everything_nested_message_oneof_field_a_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_nested_message_t *self_p)
{
    fuzzer_everything_nested_message_oneof_field_a_init(self_p);
    self_p->oneof_field.value.a = pbtools_decoder_read_int32(
        decoder_p,
        wire_type);
}

static void fuzzer_everything_nested_message_oneof_field_b_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_nested_message_t *self_p)
{
    fuzzer_everything_nested_message_oneof_field_b_init(self_p);
    pbtools_decoder_read_string(decoder_p,
                                wire_type,
                                &self_p->oneof_field.value.b_p);
}

static void fuzzer_everything_nested_message_oneof_field_c_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_nested_message_t *self_p)
{
    fuzzer_everything_nested_message_oneof_field_c_init(self_p);
    self_p->oneof_field.value.c = pbtools_decoder_read_float(
        decoder_p,
        wire_type);
}

void fuzzer_everything_nested_message_init(
    struct fuzzer_everything_nested_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct fuzzer_everything_nested_message_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->oneof_field.choice = 0;
}

void fuzzer_everything_nested_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct fuzzer_everything_nested_message_t *self_p)
{
    fuzzer_everything_nested_message_oneof_field_encode(encoder_p, &self_p->oneof_field);
}

void fuzzer_everything_nested_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_nested_message_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            fuzzer_everything_nested_message_oneof_field_a_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 10000:
            fuzzer_everything_nested_message_oneof_field_b_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 10001:
            fuzzer_everything_nested_message_oneof_field_c_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void fuzzer_everything_nested_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct fuzzer_everything_nested_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)fuzzer_everything_nested_message_encode_inner);
}

void fuzzer_everything_nested_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_nested_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct fuzzer_everything_nested_message_t),
        (pbtools_message_init_t)fuzzer_everything_nested_message_init,
        (pbtools_message_decode_inner_t)fuzzer_everything_nested_message_decode_inner);
}

void fuzzer_everything_nested_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_nested_message_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

void fuzzer_everything_init(
    struct fuzzer_everything_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct fuzzer_everything_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->optional_int32 = 0;
    self_p->optional_int64 = 0;
    self_p->optional_uint32 = 0;
    self_p->optional_uint64 = 0;
    self_p->optional_sint32 = 0;
    self_p->optional_sint64 = 0;
    self_p->optional_fixed32 = 0;
    self_p->optional_fixed64 = 0;
    self_p->optional_sfixed32 = 0;
    self_p->optional_sfixed64 = 0;
    self_p->optional_float = 0;
    self_p->optional_double = 0;
    self_p->optional_bool = 0;
    self_p->optional_string_p = "";
    pbtools_bytes_init(&self_p->optional_bytes);
    fuzzer_everything_nested_message_init(&self_p->optional_nested_message, heap_p, NULL);
    self_p->optional_nested_enum = 0;
    self_p->optional_string_piece_p = "";
    self_p->optional_cord_p = "";
    fuzzer_everything_nested_message_init(&self_p->optional_lazy_message, heap_p, NULL);
    self_p->repeated_int32.length = 0;
    self_p->repeated_int64.length = 0;
    self_p->repeated_uint32.length = 0;
    self_p->repeated_uint64.length = 0;
    self_p->repeated_sint32.length = 0;
    self_p->repeated_sint64.length = 0;
    self_p->repeated_fixed32.length = 0;
    self_p->repeated_fixed64.length = 0;
    self_p->repeated_sfixed32.length = 0;
    self_p->repeated_sfixed64.length = 0;
    self_p->repeated_float.length = 0;
    self_p->repeated_double.length = 0;
    self_p->repeated_bool.length = 0;
    self_p->repeated_string.length = 0;
    self_p->repeated_bytes.length = 0;
    self_p->repeated_nested_message.length = 0;
    self_p->repeated_nested_enum.length = 0;
    self_p->repeated_string_piece.length = 0;
    self_p->repeated_cord.length = 0;
    self_p->repeated_lazy_message.length = 0;
    self_p->oneof_field.choice = 0;
}

void fuzzer_everything_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct fuzzer_everything_t *self_p)
{
    fuzzer_everything_nested_message_encode_repeated_inner(
        encoder_p,
        57,
        &self_p->repeated_lazy_message);
    pbtools_encoder_write_repeated_string(encoder_p, 55, &self_p->repeated_cord);
    pbtools_encoder_write_repeated_string(encoder_p, 54, &self_p->repeated_string_piece);
    pbtools_encoder_write_repeated_int32(encoder_p, 51, &self_p->repeated_nested_enum);
    fuzzer_everything_nested_message_encode_repeated_inner(
        encoder_p,
        48,
        &self_p->repeated_nested_message);
    pbtools_encoder_write_repeated_bytes(encoder_p, 4500, &self_p->repeated_bytes);
    pbtools_encoder_write_repeated_string(encoder_p, 4400, &self_p->repeated_string);
    pbtools_encoder_write_repeated_bool(encoder_p, 4300, &self_p->repeated_bool);
    pbtools_encoder_write_repeated_double(encoder_p, 4200, &self_p->repeated_double);
    pbtools_encoder_write_repeated_float(encoder_p, 4100, &self_p->repeated_float);
    pbtools_encoder_write_repeated_sfixed64(encoder_p, 4000, &self_p->repeated_sfixed64);
    pbtools_encoder_write_repeated_sfixed32(encoder_p, 3900, &self_p->repeated_sfixed32);
    pbtools_encoder_write_repeated_fixed64(encoder_p, 3800, &self_p->repeated_fixed64);
    pbtools_encoder_write_repeated_fixed32(encoder_p, 3700, &self_p->repeated_fixed32);
    pbtools_encoder_write_repeated_sint64(encoder_p, 3600, &self_p->repeated_sint64);
    pbtools_encoder_write_repeated_sint32(encoder_p, 3500, &self_p->repeated_sint32);
    pbtools_encoder_write_repeated_uint64(encoder_p, 3400, &self_p->repeated_uint64);
    pbtools_encoder_write_repeated_uint32(encoder_p, 3300, &self_p->repeated_uint32);
    pbtools_encoder_write_repeated_int64(encoder_p, 3200, &self_p->repeated_int64);
    pbtools_encoder_write_repeated_int32(encoder_p, 3100, &self_p->repeated_int32);
    pbtools_encoder_sub_message_encode(
        encoder_p,
        27,
        &self_p->optional_lazy_message.base,
        (pbtools_message_encode_inner_t)fuzzer_everything_nested_message_encode_inner);
    pbtools_encoder_write_string(encoder_p, 25, self_p->optional_cord_p);
    pbtools_encoder_write_string(encoder_p, 24, self_p->optional_string_piece_p);
    pbtools_encoder_write_enum(encoder_p, 21, self_p->optional_nested_enum);
    pbtools_encoder_sub_message_encode(
        encoder_p,
        18,
        &self_p->optional_nested_message.base,
        (pbtools_message_encode_inner_t)fuzzer_everything_nested_message_encode_inner);
    pbtools_encoder_write_bytes(encoder_p, 15, &self_p->optional_bytes);
    pbtools_encoder_write_string(encoder_p, 14, self_p->optional_string_p);
    pbtools_encoder_write_bool(encoder_p, 13, self_p->optional_bool);
    pbtools_encoder_write_double(encoder_p, 12, self_p->optional_double);
    pbtools_encoder_write_float(encoder_p, 11, self_p->optional_float);
    pbtools_encoder_write_sfixed64(encoder_p, 10, self_p->optional_sfixed64);
    pbtools_encoder_write_sfixed32(encoder_p, 9, self_p->optional_sfixed32);
    pbtools_encoder_write_fixed64(encoder_p, 8, self_p->optional_fixed64);
    pbtools_encoder_write_fixed32(encoder_p, 7, self_p->optional_fixed32);
    pbtools_encoder_write_sint64(encoder_p, 6, self_p->optional_sint64);
    pbtools_encoder_write_sint32(encoder_p, 5, self_p->optional_sint32);
    pbtools_encoder_write_uint64(encoder_p, 4, self_p->optional_uint64);
    pbtools_encoder_write_uint32(encoder_p, 3, self_p->optional_uint32);
    pbtools_encoder_write_int64(encoder_p, 2, self_p->optional_int64);
    pbtools_encoder_write_int32(encoder_p, 1, self_p->optional_int32);
    fuzzer_everything_oneof_field_encode(encoder_p, &self_p->oneof_field);
}

void fuzzer_everything_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->optional_int32 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 2:
            self_p->optional_int64 = pbtools_decoder_read_int64(decoder_p, wire_type);
            break;

        case 3:
            self_p->optional_uint32 = pbtools_decoder_read_uint32(decoder_p, wire_type);
            break;

        case 4:
            self_p->optional_uint64 = pbtools_decoder_read_uint64(decoder_p, wire_type);
            break;

        case 5:
            self_p->optional_sint32 = pbtools_decoder_read_sint32(decoder_p, wire_type);
            break;

        case 6:
            self_p->optional_sint64 = pbtools_decoder_read_sint64(decoder_p, wire_type);
            break;

        case 7:
            self_p->optional_fixed32 = pbtools_decoder_read_fixed32(decoder_p, wire_type);
            break;

        case 8:
            self_p->optional_fixed64 = pbtools_decoder_read_fixed64(decoder_p, wire_type);
            break;

        case 9:
            self_p->optional_sfixed32 = pbtools_decoder_read_sfixed32(decoder_p, wire_type);
            break;

        case 10:
            self_p->optional_sfixed64 = pbtools_decoder_read_sfixed64(decoder_p, wire_type);
            break;

        case 11:
            self_p->optional_float = pbtools_decoder_read_float(decoder_p, wire_type);
            break;

        case 12:
            self_p->optional_double = pbtools_decoder_read_double(decoder_p, wire_type);
            break;

        case 13:
            self_p->optional_bool = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 14:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->optional_string_p);
            break;

        case 15:
            pbtools_decoder_read_bytes(decoder_p, wire_type, &self_p->optional_bytes);
            break;

        case 18:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->optional_nested_message.base,
                (pbtools_message_decode_inner_t)fuzzer_everything_nested_message_decode_inner);
            break;

        case 21:
            self_p->optional_nested_enum = pbtools_decoder_read_enum(decoder_p, wire_type);
            break;

        case 24:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->optional_string_piece_p);
            break;

        case 25:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->optional_cord_p);
            break;

        case 27:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->optional_lazy_message.base,
                (pbtools_message_decode_inner_t)fuzzer_everything_nested_message_decode_inner);
            break;

        case 3100:
            pbtools_decoder_read_repeated_int32(
                decoder_p,
                wire_type,
                &self_p->repeated_int32);
            break;

        case 3200:
            pbtools_decoder_read_repeated_int64(
                decoder_p,
                wire_type,
                &self_p->repeated_int64);
            break;

        case 3300:
            pbtools_decoder_read_repeated_uint32(
                decoder_p,
                wire_type,
                &self_p->repeated_uint32);
            break;

        case 3400:
            pbtools_decoder_read_repeated_uint64(
                decoder_p,
                wire_type,
                &self_p->repeated_uint64);
            break;

        case 3500:
            pbtools_decoder_read_repeated_sint32(
                decoder_p,
                wire_type,
                &self_p->repeated_sint32);
            break;

        case 3600:
            pbtools_decoder_read_repeated_sint64(
                decoder_p,
                wire_type,
                &self_p->repeated_sint64);
            break;

        case 3700:
            pbtools_decoder_read_repeated_fixed32(
                decoder_p,
                wire_type,
                &self_p->repeated_fixed32);
            break;

        case 3800:
            pbtools_decoder_read_repeated_fixed64(
                decoder_p,
                wire_type,
                &self_p->repeated_fixed64);
            break;

        case 3900:
            pbtools_decoder_read_repeated_sfixed32(
                decoder_p,
                wire_type,
                &self_p->repeated_sfixed32);
            break;

        case 4000:
            pbtools_decoder_read_repeated_sfixed64(
                decoder_p,
                wire_type,
                &self_p->repeated_sfixed64);
            break;

        case 4100:
            pbtools_decoder_read_repeated_float(
                decoder_p,
                wire_type,
                &self_p->repeated_float);
            break;

        case 4200:
            pbtools_decoder_read_repeated_double(
                decoder_p,
                wire_type,
                &self_p->repeated_double);
            break;

        case 4300:
            pbtools_decoder_read_repeated_bool(
                decoder_p,
                wire_type,
                &self_p->repeated_bool);
            break;

        case 4400:
            pbtools_decoder_read_repeated_string(
                decoder_p,
                wire_type,
                &self_p->repeated_string);
            break;

        case 4500:
            pbtools_decoder_read_repeated_bytes(
                decoder_p,
                wire_type,
                &self_p->repeated_bytes);
            break;

        case 48:
            fuzzer_everything_nested_message_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->repeated_nested_message);
            break;

        case 51:
            pbtools_decoder_read_repeated_int32(
                decoder_p,
                wire_type,
                &self_p->repeated_nested_enum);
            break;

        case 54:
            pbtools_decoder_read_repeated_string(
                decoder_p,
                wire_type,
                &self_p->repeated_string_piece);
            break;

        case 55:
            pbtools_decoder_read_repeated_string(
                decoder_p,
                wire_type,
                &self_p->repeated_cord);
            break;

        case 57:
            fuzzer_everything_nested_message_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->repeated_lazy_message);
            break;

        case 111:
            fuzzer_everything_oneof_field_oneof_uint32_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 112:
            fuzzer_everything_oneof_field_oneof_nested_message_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 113:
            fuzzer_everything_oneof_field_oneof_string_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 114:
            fuzzer_everything_oneof_field_oneof_bytes_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    pbtools_decoder_finalize_repeated_int32(
        decoder_p,
        &self_p->repeated_int32);
    pbtools_decoder_finalize_repeated_int64(
        decoder_p,
        &self_p->repeated_int64);
    pbtools_decoder_finalize_repeated_uint32(
        decoder_p,
        &self_p->repeated_uint32);
    pbtools_decoder_finalize_repeated_uint64(
        decoder_p,
        &self_p->repeated_uint64);
    pbtools_decoder_finalize_repeated_sint32(
        decoder_p,
        &self_p->repeated_sint32);
    pbtools_decoder_finalize_repeated_sint64(
        decoder_p,
        &self_p->repeated_sint64);
    pbtools_decoder_finalize_repeated_fixed32(
        decoder_p,
        &self_p->repeated_fixed32);
    pbtools_decoder_finalize_repeated_fixed64(
        decoder_p,
        &self_p->repeated_fixed64);
    pbtools_decoder_finalize_repeated_sfixed32(
        decoder_p,
        &self_p->repeated_sfixed32);
    pbtools_decoder_finalize_repeated_sfixed64(
        decoder_p,
        &self_p->repeated_sfixed64);
    pbtools_decoder_finalize_repeated_float(
        decoder_p,
        &self_p->repeated_float);
    pbtools_decoder_finalize_repeated_double(
        decoder_p,
        &self_p->repeated_double);
    pbtools_decoder_finalize_repeated_bool(
        decoder_p,
        &self_p->repeated_bool);
    pbtools_decoder_finalize_repeated_string(
        decoder_p,
        &self_p->repeated_string);
    pbtools_decoder_finalize_repeated_bytes(
        decoder_p,
        &self_p->repeated_bytes);
    fuzzer_everything_nested_message_finalize_repeated_inner(
        decoder_p,
        &self_p->repeated_nested_message);
    pbtools_decoder_finalize_repeated_int32(
        decoder_p,
        &self_p->repeated_nested_enum);
    pbtools_decoder_finalize_repeated_string(
        decoder_p,
        &self_p->repeated_string_piece);
    pbtools_decoder_finalize_repeated_string(
        decoder_p,
        &self_p->repeated_cord);
    fuzzer_everything_nested_message_finalize_repeated_inner(
        decoder_p,
        &self_p->repeated_lazy_message);
}

int fuzzer_everything_repeated_int32_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_int32(
                &self_p->base,
                length,
                &self_p->repeated_int32));
}

int fuzzer_everything_repeated_int64_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_int64(
                &self_p->base,
                length,
                &self_p->repeated_int64));
}

int fuzzer_everything_repeated_uint32_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_uint32(
                &self_p->base,
                length,
                &self_p->repeated_uint32));
}

int fuzzer_everything_repeated_uint64_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_uint64(
                &self_p->base,
                length,
                &self_p->repeated_uint64));
}

int fuzzer_everything_repeated_sint32_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_sint32(
                &self_p->base,
                length,
                &self_p->repeated_sint32));
}

int fuzzer_everything_repeated_sint64_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_sint64(
                &self_p->base,
                length,
                &self_p->repeated_sint64));
}

int fuzzer_everything_repeated_fixed32_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_fixed32(
                &self_p->base,
                length,
                &self_p->repeated_fixed32));
}

int fuzzer_everything_repeated_fixed64_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_fixed64(
                &self_p->base,
                length,
                &self_p->repeated_fixed64));
}

int fuzzer_everything_repeated_sfixed32_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_sfixed32(
                &self_p->base,
                length,
                &self_p->repeated_sfixed32));
}

int fuzzer_everything_repeated_sfixed64_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_sfixed64(
                &self_p->base,
                length,
                &self_p->repeated_sfixed64));
}

int fuzzer_everything_repeated_float_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_float(
                &self_p->base,
                length,
                &self_p->repeated_float));
}

int fuzzer_everything_repeated_double_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_double(
                &self_p->base,
                length,
                &self_p->repeated_double));
}

int fuzzer_everything_repeated_bool_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_bool(
                &self_p->base,
                length,
                &self_p->repeated_bool));
}

int fuzzer_everything_repeated_string_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_string(
                &self_p->base,
                length,
                &self_p->repeated_string));
}

int fuzzer_everything_repeated_bytes_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_bytes(
                &self_p->base,
                length,
                &self_p->repeated_bytes));
}

int fuzzer_everything_repeated_nested_message_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->repeated_nested_message,
                length,
                self_p->base.heap_p,
                sizeof(struct fuzzer_everything_nested_message_t),
                (pbtools_message_init_t)fuzzer_everything_nested_message_init));
}

int fuzzer_everything_repeated_nested_enum_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_int32(
                &self_p->base,
                length,
                &self_p->repeated_nested_enum));
}

int fuzzer_everything_repeated_string_piece_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_string(
                &self_p->base,
                length,
                &self_p->repeated_string_piece));
}

int fuzzer_everything_repeated_cord_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_string(
                &self_p->base,
                length,
                &self_p->repeated_cord));
}

int fuzzer_everything_repeated_lazy_message_alloc(
    struct fuzzer_everything_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->repeated_lazy_message,
                length,
                self_p->base.heap_p,
                sizeof(struct fuzzer_everything_nested_message_t),
                (pbtools_message_init_t)fuzzer_everything_nested_message_init));
}

void fuzzer_everything_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct fuzzer_everything_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)fuzzer_everything_encode_inner);
}

void fuzzer_everything_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct fuzzer_everything_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct fuzzer_everything_t),
        (pbtools_message_init_t)fuzzer_everything_init,
        (pbtools_message_decode_inner_t)fuzzer_everything_decode_inner);
}

void fuzzer_everything_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fuzzer_everything_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct fuzzer_everything_t *
fuzzer_everything_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct fuzzer_everything_t),
                (pbtools_message_init_t)fuzzer_everything_init));
}

int fuzzer_everything_encode(
    struct fuzzer_everything_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)fuzzer_everything_encode_inner));
}

int fuzzer_everything_decode(
    struct fuzzer_everything_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)fuzzer_everything_decode_inner));
}
