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
#include "address_book.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void address_book_person_phone_number_init(
    struct address_book_person_phone_number_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct address_book_person_phone_number_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->number_p = "";
    self_p->type = 0;
}

void address_book_person_phone_number_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct address_book_person_phone_number_t *self_p)
{
    pbtools_encoder_write_enum(encoder_p, 2, self_p->type);
    pbtools_encoder_write_string(encoder_p, 1, self_p->number_p);
}

void address_book_person_phone_number_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_phone_number_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->number_p);
            break;

        case 2:
            self_p->type = pbtools_decoder_read_enum(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void address_book_person_phone_number_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct address_book_person_phone_number_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)address_book_person_phone_number_encode_inner);
}

void address_book_person_phone_number_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct address_book_person_phone_number_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct address_book_person_phone_number_t),
        (pbtools_message_init_t)address_book_person_phone_number_init,
        (pbtools_message_decode_inner_t)address_book_person_phone_number_decode_inner);
}

void address_book_person_phone_number_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_phone_number_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

void address_book_person_init(
    struct address_book_person_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct address_book_person_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->name_p = "";
    self_p->id = 0;
    self_p->email_p = "";
    self_p->phones.length = 0;
}

void address_book_person_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct address_book_person_t *self_p)
{
    address_book_person_phone_number_encode_repeated_inner(
        encoder_p,
        4,
        &self_p->phones);
    pbtools_encoder_write_string(encoder_p, 3, self_p->email_p);
    pbtools_encoder_write_int32(encoder_p, 2, self_p->id);
    pbtools_encoder_write_string(encoder_p, 1, self_p->name_p);
}

void address_book_person_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->name_p);
            break;

        case 2:
            self_p->id = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 3:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->email_p);
            break;

        case 4:
            address_book_person_phone_number_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->phones);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    address_book_person_phone_number_finalize_repeated_inner(
        decoder_p,
        &self_p->phones);
}

int address_book_person_phones_alloc(
    struct address_book_person_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->phones,
                length,
                self_p->base.heap_p,
                sizeof(struct address_book_person_phone_number_t),
                (pbtools_message_init_t)address_book_person_phone_number_init));
}

void address_book_person_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct address_book_person_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)address_book_person_encode_inner);
}

void address_book_person_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct address_book_person_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct address_book_person_t),
        (pbtools_message_init_t)address_book_person_init,
        (pbtools_message_decode_inner_t)address_book_person_decode_inner);
}

void address_book_person_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct address_book_person_t *
address_book_person_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct address_book_person_t),
                (pbtools_message_init_t)address_book_person_init));
}

int address_book_person_encode(
    struct address_book_person_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)address_book_person_encode_inner));
}

int address_book_person_decode(
    struct address_book_person_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)address_book_person_decode_inner));
}

void address_book_address_book_init(
    struct address_book_address_book_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct address_book_address_book_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->people.length = 0;
}

void address_book_address_book_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct address_book_address_book_t *self_p)
{
    address_book_person_encode_repeated_inner(
        encoder_p,
        1,
        &self_p->people);
}

void address_book_address_book_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_address_book_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            address_book_person_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->people);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    address_book_person_finalize_repeated_inner(
        decoder_p,
        &self_p->people);
}

int address_book_address_book_people_alloc(
    struct address_book_address_book_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->people,
                length,
                self_p->base.heap_p,
                sizeof(struct address_book_person_t),
                (pbtools_message_init_t)address_book_person_init));
}

void address_book_address_book_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct address_book_address_book_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)address_book_address_book_encode_inner);
}

void address_book_address_book_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct address_book_address_book_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct address_book_address_book_t),
        (pbtools_message_init_t)address_book_address_book_init,
        (pbtools_message_decode_inner_t)address_book_address_book_decode_inner);
}

void address_book_address_book_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_address_book_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct address_book_address_book_t *
address_book_address_book_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct address_book_address_book_t),
                (pbtools_message_init_t)address_book_address_book_init));
}

int address_book_address_book_encode(
    struct address_book_address_book_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)address_book_address_book_encode_inner));
}

int address_book_address_book_decode(
    struct address_book_address_book_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)address_book_address_book_decode_inner));
}
