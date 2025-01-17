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
#include "oneof.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void oneof_message_value_v1_init(
    struct oneof_message_t *self_p)
{
    self_p->value.choice = oneof_message_value_choice_v1_e;
    self_p->value.value.v1 = 0;
}

void oneof_message_value_v2_init(
    struct oneof_message_t *self_p)
{
    self_p->value.choice = oneof_message_value_choice_v2_e;
    self_p->value.value.v2_p = "";
}

void oneof_message_value_encode(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message_value_oneof_t *self_p)
{
    switch (self_p->choice) {

    case oneof_message_value_choice_v1_e:
        pbtools_encoder_write_int32(
            encoder_p,
            1,
            self_p->value.v1);
        break;

    case oneof_message_value_choice_v2_e:
        pbtools_encoder_write_string(
            encoder_p,
            2,
            self_p->value.v2_p);
        break;

    default:
        break;
    }
}

static void oneof_message_value_v1_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message_t *self_p)
{
    oneof_message_value_v1_init(self_p);
    self_p->value.value.v1 = pbtools_decoder_read_int32(
        decoder_p,
        wire_type);
}

static void oneof_message_value_v2_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message_t *self_p)
{
    oneof_message_value_v2_init(self_p);
    pbtools_decoder_read_string(decoder_p,
                                wire_type,
                                &self_p->value.value.v2_p);
}

void oneof_message_init(
    struct oneof_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_message_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value.choice = 0;
}

void oneof_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message_t *self_p)
{
    oneof_message_value_encode(encoder_p, &self_p->value);
}

void oneof_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            oneof_message_value_v1_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 2:
            oneof_message_value_v2_decode(
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

void oneof_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_message_encode_inner);
}

void oneof_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_message_t),
        (pbtools_message_init_t)oneof_message_init,
        (pbtools_message_decode_inner_t)oneof_message_decode_inner);
}

void oneof_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct oneof_message_t *
oneof_message_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct oneof_message_t),
                (pbtools_message_init_t)oneof_message_init));
}

int oneof_message_encode(
    struct oneof_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)oneof_message_encode_inner));
}

int oneof_message_decode(
    struct oneof_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)oneof_message_decode_inner));
}

void oneof_message2_oneof1_v4_init(
    struct oneof_message2_t *self_p)
{
    self_p->oneof1.choice = oneof_message2_oneof1_choice_v4_e;
    oneof_message2_foo_init(
        &self_p->oneof1.value.v4,
        self_p->base.heap_p,
        NULL);
}

void oneof_message2_oneof1_v5_init(
    struct oneof_message2_t *self_p)
{
    self_p->oneof1.choice = oneof_message2_oneof1_choice_v5_e;
    pbtools_bytes_init(&self_p->oneof1.value.v5);
}

void oneof_message2_oneof1_v6_init(
    struct oneof_message2_t *self_p)
{
    self_p->oneof1.choice = oneof_message2_oneof1_choice_v6_e;
    self_p->oneof1.value.v6 = 0;
}

void oneof_message2_oneof1_encode(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message2_oneof1_oneof_t *self_p)
{
    switch (self_p->choice) {

    case oneof_message2_oneof1_choice_v4_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            4,
            &self_p->value.v4.base,
            (pbtools_message_encode_inner_t)oneof_message2_foo_encode_inner);
        break;

    case oneof_message2_oneof1_choice_v5_e:
        pbtools_encoder_write_bytes(
            encoder_p,
            5,
            &self_p->value.v5);
        break;

    case oneof_message2_oneof1_choice_v6_e:
        pbtools_encoder_write_enum(
            encoder_p,
            6,
            self_p->value.v6);
        break;

    default:
        break;
    }
}

static void oneof_message2_oneof1_v4_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof1_v4_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof1.value.v4.base,
        (pbtools_message_decode_inner_t)oneof_message2_foo_decode_inner);
}

static void oneof_message2_oneof1_v5_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof1_v5_init(self_p);
    pbtools_decoder_read_bytes(decoder_p,
                               wire_type,
                               &self_p->oneof1.value.v5);
}

static void oneof_message2_oneof1_v6_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof1_v6_init(self_p);
    self_p->oneof1.value.v6 = pbtools_decoder_read_enum(
        decoder_p,
        wire_type);
}

void oneof_message2_oneof2_v1_init(
    struct oneof_message2_t *self_p)
{
    self_p->oneof2.choice = oneof_message2_oneof2_choice_v1_e;
    self_p->oneof2.value.v1 = 0;
}

void oneof_message2_oneof2_v2_init(
    struct oneof_message2_t *self_p)
{
    self_p->oneof2.choice = oneof_message2_oneof2_choice_v2_e;
    oneof_message2_foo_init(
        &self_p->oneof2.value.v2,
        self_p->base.heap_p,
        NULL);
}

void oneof_message2_oneof2_v3_init(
    struct oneof_message2_t *self_p)
{
    self_p->oneof2.choice = oneof_message2_oneof2_choice_v3_e;
    oneof_message_init(
        &self_p->oneof2.value.v3,
        self_p->base.heap_p,
        NULL);
}

void oneof_message2_oneof2_encode(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message2_oneof2_oneof_t *self_p)
{
    switch (self_p->choice) {

    case oneof_message2_oneof2_choice_v1_e:
        pbtools_encoder_write_bool(
            encoder_p,
            1,
            self_p->value.v1);
        break;

    case oneof_message2_oneof2_choice_v2_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            2,
            &self_p->value.v2.base,
            (pbtools_message_encode_inner_t)oneof_message2_foo_encode_inner);
        break;

    case oneof_message2_oneof2_choice_v3_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            3,
            &self_p->value.v3.base,
            (pbtools_message_encode_inner_t)oneof_message_encode_inner);
        break;

    default:
        break;
    }
}

static void oneof_message2_oneof2_v1_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof2_v1_init(self_p);
    self_p->oneof2.value.v1 = pbtools_decoder_read_bool(
        decoder_p,
        wire_type);
}

static void oneof_message2_oneof2_v2_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof2_v2_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof2.value.v2.base,
        (pbtools_message_decode_inner_t)oneof_message2_foo_decode_inner);
}

static void oneof_message2_oneof2_v3_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof2_v3_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof2.value.v3.base,
        (pbtools_message_decode_inner_t)oneof_message_decode_inner);
}

void oneof_message2_foo_init(
    struct oneof_message2_foo_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_message2_foo_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->bar = 0;
}

void oneof_message2_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message2_foo_t *self_p)
{
    pbtools_encoder_write_int32(encoder_p, 55, self_p->bar);
}

void oneof_message2_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message2_foo_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 55:
            self_p->bar = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void oneof_message2_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_message2_foo_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_message2_foo_encode_inner);
}

void oneof_message2_foo_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_foo_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_message2_foo_t),
        (pbtools_message_init_t)oneof_message2_foo_init,
        (pbtools_message_decode_inner_t)oneof_message2_foo_decode_inner);
}

void oneof_message2_foo_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message2_foo_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

void oneof_message2_init(
    struct oneof_message2_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_message2_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->oneof1.choice = 0;
    self_p->oneof2.choice = 0;
}

void oneof_message2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message2_t *self_p)
{
    oneof_message2_oneof1_encode(encoder_p, &self_p->oneof1);
    oneof_message2_oneof2_encode(encoder_p, &self_p->oneof2);
}

void oneof_message2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message2_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 4:
            oneof_message2_oneof1_v4_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 5:
            oneof_message2_oneof1_v5_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 6:
            oneof_message2_oneof1_v6_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 1:
            oneof_message2_oneof2_v1_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 2:
            oneof_message2_oneof2_v2_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 3:
            oneof_message2_oneof2_v3_decode(
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

void oneof_message2_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_message2_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_message2_encode_inner);
}

void oneof_message2_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message2_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_message2_t),
        (pbtools_message_init_t)oneof_message2_init,
        (pbtools_message_decode_inner_t)oneof_message2_decode_inner);
}

void oneof_message2_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message2_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct oneof_message2_t *
oneof_message2_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct oneof_message2_t),
                (pbtools_message_init_t)oneof_message2_init));
}

int oneof_message2_encode(
    struct oneof_message2_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)oneof_message2_encode_inner));
}

int oneof_message2_decode(
    struct oneof_message2_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)oneof_message2_decode_inner));
}

void oneof_message3_oneof1_v1_init(
    struct oneof_message3_t *self_p)
{
    self_p->oneof1.choice = oneof_message3_oneof1_choice_v1_e;
    oneof_message3_bar_init(
        &self_p->oneof1.value.v1,
        self_p->base.heap_p,
        NULL);
}

void oneof_message3_oneof1_encode(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message3_oneof1_oneof_t *self_p)
{
    switch (self_p->choice) {

    case oneof_message3_oneof1_choice_v1_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            1,
            &self_p->value.v1.base,
            (pbtools_message_encode_inner_t)oneof_message3_bar_encode_inner);
        break;

    default:
        break;
    }
}

static void oneof_message3_oneof1_v1_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message3_t *self_p)
{
    oneof_message3_oneof1_v1_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof1.value.v1.base,
        (pbtools_message_decode_inner_t)oneof_message3_bar_decode_inner);
}

void oneof_message3_foo_inner_oneof_v1_init(
    struct oneof_message3_foo_t *self_p)
{
    self_p->inner_oneof.choice = oneof_message3_foo_inner_oneof_choice_v1_e;
    self_p->inner_oneof.value.v1 = 0;
}

void oneof_message3_foo_inner_oneof_v2_init(
    struct oneof_message3_foo_t *self_p)
{
    self_p->inner_oneof.choice = oneof_message3_foo_inner_oneof_choice_v2_e;
    pbtools_bytes_init(&self_p->inner_oneof.value.v2);
}

void oneof_message3_foo_inner_oneof_encode(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message3_foo_inner_oneof_oneof_t *self_p)
{
    switch (self_p->choice) {

    case oneof_message3_foo_inner_oneof_choice_v1_e:
        pbtools_encoder_write_bool(
            encoder_p,
            1,
            self_p->value.v1);
        break;

    case oneof_message3_foo_inner_oneof_choice_v2_e:
        pbtools_encoder_write_bytes(
            encoder_p,
            2,
            &self_p->value.v2);
        break;

    default:
        break;
    }
}

static void oneof_message3_foo_inner_oneof_v1_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message3_foo_t *self_p)
{
    oneof_message3_foo_inner_oneof_v1_init(self_p);
    self_p->inner_oneof.value.v1 = pbtools_decoder_read_bool(
        decoder_p,
        wire_type);
}

static void oneof_message3_foo_inner_oneof_v2_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message3_foo_t *self_p)
{
    oneof_message3_foo_inner_oneof_v2_init(self_p);
    pbtools_decoder_read_bytes(decoder_p,
                               wire_type,
                               &self_p->inner_oneof.value.v2);
}

void oneof_message3_foo_init(
    struct oneof_message3_foo_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_message3_foo_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->inner_oneof.choice = 0;
}

void oneof_message3_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message3_foo_t *self_p)
{
    oneof_message3_foo_inner_oneof_encode(encoder_p, &self_p->inner_oneof);
}

void oneof_message3_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message3_foo_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            oneof_message3_foo_inner_oneof_v1_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 2:
            oneof_message3_foo_inner_oneof_v2_decode(
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

void oneof_message3_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_message3_foo_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_message3_foo_encode_inner);
}

void oneof_message3_foo_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message3_foo_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_message3_foo_t),
        (pbtools_message_init_t)oneof_message3_foo_init,
        (pbtools_message_decode_inner_t)oneof_message3_foo_decode_inner);
}

void oneof_message3_foo_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message3_foo_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

void oneof_message3_bar_init(
    struct oneof_message3_bar_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_message3_bar_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->foo.length = 0;
}

void oneof_message3_bar_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message3_bar_t *self_p)
{
    oneof_message3_foo_encode_repeated_inner(
        encoder_p,
        1,
        &self_p->foo);
}

void oneof_message3_bar_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message3_bar_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            oneof_message3_foo_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->foo);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    oneof_message3_foo_finalize_repeated_inner(
        decoder_p,
        &self_p->foo);
}

int oneof_message3_bar_foo_alloc(
    struct oneof_message3_bar_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->foo,
                length,
                self_p->base.heap_p,
                sizeof(struct oneof_message3_foo_t),
                (pbtools_message_init_t)oneof_message3_foo_init));
}

void oneof_message3_bar_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_message3_bar_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_message3_bar_encode_inner);
}

void oneof_message3_bar_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message3_bar_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_message3_bar_t),
        (pbtools_message_init_t)oneof_message3_bar_init,
        (pbtools_message_decode_inner_t)oneof_message3_bar_decode_inner);
}

void oneof_message3_bar_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message3_bar_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

void oneof_message3_init(
    struct oneof_message3_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_message3_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->oneof1.choice = 0;
}

void oneof_message3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_message3_t *self_p)
{
    oneof_message3_oneof1_encode(encoder_p, &self_p->oneof1);
}

void oneof_message3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message3_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            oneof_message3_oneof1_v1_decode(
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

void oneof_message3_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_message3_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_message3_encode_inner);
}

void oneof_message3_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_message3_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_message3_t),
        (pbtools_message_init_t)oneof_message3_init,
        (pbtools_message_decode_inner_t)oneof_message3_decode_inner);
}

void oneof_message3_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_message3_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct oneof_message3_t *
oneof_message3_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct oneof_message3_t),
                (pbtools_message_init_t)oneof_message3_init));
}

int oneof_message3_encode(
    struct oneof_message3_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)oneof_message3_encode_inner));
}

int oneof_message3_decode(
    struct oneof_message3_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)oneof_message3_decode_inner));
}
