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

#include "tags.h"

static void tags_message1_init(
    struct tags_message1_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message1_t *next_p);

static void tags_message1_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message1_t *self_p);

static void tags_message1_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message1_t *self_p);

static void tags_message2_init(
    struct tags_message2_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message2_t *next_p);

static void tags_message2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message2_t *self_p);

static void tags_message2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message2_t *self_p);

static void tags_message3_init(
    struct tags_message3_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message3_t *next_p);

static void tags_message3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message3_t *self_p);

static void tags_message3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message3_t *self_p);

static void tags_message4_init(
    struct tags_message4_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message4_t *next_p);

static void tags_message4_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message4_t *self_p);

static void tags_message4_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message4_t *self_p);

static void tags_message5_init(
    struct tags_message5_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message5_t *next_p);

static void tags_message5_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message5_t *self_p);

static void tags_message5_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message5_t *self_p);

static void tags_message6_init(
    struct tags_message6_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message6_t *next_p);

static void tags_message6_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message6_t *self_p);

static void tags_message6_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message6_t *self_p);

static void tags_message1_init(
    struct tags_message1_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message1_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value = 0;
}

static void tags_message1_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message1_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 1, self_p->value);
}

static void tags_message1_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message1_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

struct tags_message1_t *
tags_message1_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct tags_message1_t),
                (pbtools_message_init_t)tags_message1_init));
}

int tags_message1_encode(
    struct tags_message1_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)tags_message1_encode_inner));
}

int tags_message1_decode(
    struct tags_message1_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)tags_message1_decode_inner));
}

static void tags_message2_init(
    struct tags_message2_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message2_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value = 0;
}

static void tags_message2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message2_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 15, self_p->value);
}

static void tags_message2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message2_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 15:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

struct tags_message2_t *
tags_message2_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct tags_message2_t),
                (pbtools_message_init_t)tags_message2_init));
}

int tags_message2_encode(
    struct tags_message2_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)tags_message2_encode_inner));
}

int tags_message2_decode(
    struct tags_message2_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)tags_message2_decode_inner));
}

static void tags_message3_init(
    struct tags_message3_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message3_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value = 0;
}

static void tags_message3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message3_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 16, self_p->value);
}

static void tags_message3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message3_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 16:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

struct tags_message3_t *
tags_message3_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct tags_message3_t),
                (pbtools_message_init_t)tags_message3_init));
}

int tags_message3_encode(
    struct tags_message3_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)tags_message3_encode_inner));
}

int tags_message3_decode(
    struct tags_message3_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)tags_message3_decode_inner));
}

static void tags_message4_init(
    struct tags_message4_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message4_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value = 0;
}

static void tags_message4_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message4_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 2047, self_p->value);
}

static void tags_message4_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message4_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 2047:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

struct tags_message4_t *
tags_message4_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct tags_message4_t),
                (pbtools_message_init_t)tags_message4_init));
}

int tags_message4_encode(
    struct tags_message4_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)tags_message4_encode_inner));
}

int tags_message4_decode(
    struct tags_message4_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)tags_message4_decode_inner));
}

static void tags_message5_init(
    struct tags_message5_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message5_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value = 0;
}

static void tags_message5_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message5_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 2048, self_p->value);
}

static void tags_message5_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message5_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 2048:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

struct tags_message5_t *
tags_message5_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct tags_message5_t),
                (pbtools_message_init_t)tags_message5_init));
}

int tags_message5_encode(
    struct tags_message5_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)tags_message5_encode_inner));
}

int tags_message5_decode(
    struct tags_message5_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)tags_message5_decode_inner));
}

static void tags_message6_init(
    struct tags_message6_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct tags_message6_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->value = 0;
}

static void tags_message6_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct tags_message6_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 536870911, self_p->value);
}

static void tags_message6_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct tags_message6_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 536870911:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

struct tags_message6_t *
tags_message6_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct tags_message6_t),
                (pbtools_message_init_t)tags_message6_init));
}

int tags_message6_encode(
    struct tags_message6_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)tags_message6_encode_inner));
}

int tags_message6_decode(
    struct tags_message6_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)tags_message6_decode_inner));
}
