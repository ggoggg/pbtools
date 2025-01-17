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

#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "pbtools.h"

/**
 * Enum address_book.Person.PhoneType.
 */
enum address_book_person_phone_type_e {
    address_book_person_phone_type_mobile_e = 0,
    address_book_person_phone_type_home_e = 1,
    address_book_person_phone_type_work_e = 2
};

/**
 * Message address_book.Person.PhoneNumber.
 */
struct address_book_person_phone_number_repeated_t {
    int length;
    struct address_book_person_phone_number_t **items_pp;
    struct address_book_person_phone_number_t *head_p;
    struct address_book_person_phone_number_t *tail_p;
};

struct address_book_person_phone_number_t {
    struct pbtools_message_base_t base;
    char *number_p;
    enum address_book_person_phone_type_e type;
};

/**
 * Message address_book.Person.
 */
struct address_book_person_repeated_t {
    int length;
    struct address_book_person_t **items_pp;
    struct address_book_person_t *head_p;
    struct address_book_person_t *tail_p;
};

struct address_book_person_t {
    struct pbtools_message_base_t base;
    char *name_p;
    int32_t id;
    char *email_p;
    struct address_book_person_phone_number_repeated_t phones;
};

/**
 * Message address_book.AddressBook.
 */
struct address_book_address_book_repeated_t {
    int length;
    struct address_book_address_book_t **items_pp;
    struct address_book_address_book_t *head_p;
    struct address_book_address_book_t *tail_p;
};

struct address_book_address_book_t {
    struct pbtools_message_base_t base;
    struct address_book_person_repeated_t people;
};

int address_book_person_phones_alloc(
    struct address_book_person_t *self_p,
    int length);

/**
 * Encoding and decoding of address_book.Person.
 */
struct address_book_person_t *
address_book_person_new(
    void *workspace_p,
    size_t size);

int address_book_person_encode(
    struct address_book_person_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int address_book_person_decode(
    struct address_book_person_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int address_book_address_book_people_alloc(
    struct address_book_address_book_t *self_p,
    int length);

/**
 * Encoding and decoding of address_book.AddressBook.
 */
struct address_book_address_book_t *
address_book_address_book_new(
    void *workspace_p,
    size_t size);

int address_book_address_book_encode(
    struct address_book_address_book_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int address_book_address_book_decode(
    struct address_book_address_book_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void address_book_person_init(
    struct address_book_person_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct address_book_person_t *next_p);

void address_book_person_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct address_book_person_t *self_p);

void address_book_person_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_t *self_p);

void address_book_person_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct address_book_person_repeated_t *repeated_p);

void address_book_person_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct address_book_person_repeated_t *repeated_p);

void address_book_person_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_repeated_t *repeated_p);

void address_book_person_phone_number_init(
    struct address_book_person_phone_number_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct address_book_person_phone_number_t *next_p);

void address_book_person_phone_number_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct address_book_person_phone_number_t *self_p);

void address_book_person_phone_number_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_phone_number_t *self_p);

void address_book_person_phone_number_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct address_book_person_phone_number_repeated_t *repeated_p);

void address_book_person_phone_number_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct address_book_person_phone_number_repeated_t *repeated_p);

void address_book_person_phone_number_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_person_phone_number_repeated_t *repeated_p);

void address_book_address_book_init(
    struct address_book_address_book_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct address_book_address_book_t *next_p);

void address_book_address_book_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct address_book_address_book_t *self_p);

void address_book_address_book_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_address_book_t *self_p);

void address_book_address_book_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct address_book_address_book_repeated_t *repeated_p);

void address_book_address_book_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct address_book_address_book_repeated_t *repeated_p);

void address_book_address_book_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct address_book_address_book_repeated_t *repeated_p);

#endif
