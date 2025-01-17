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

#ifndef SERVICE_H
#define SERVICE_H

#include "pbtools.h"

/**
 * Message service.Request.
 */
struct service_request_repeated_t {
    int length;
    struct service_request_t **items_pp;
    struct service_request_t *head_p;
    struct service_request_t *tail_p;
};

struct service_request_t {
    struct pbtools_message_base_t base;
    char *value_p;
};

/**
 * Message service.Response.
 */
struct service_response_repeated_t {
    int length;
    struct service_response_t **items_pp;
    struct service_response_t *head_p;
    struct service_response_t *tail_p;
};

struct service_response_t {
    struct pbtools_message_base_t base;
    char *value_p;
};

/**
 * Encoding and decoding of service.Request.
 */
struct service_request_t *
service_request_new(
    void *workspace_p,
    size_t size);

int service_request_encode(
    struct service_request_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int service_request_decode(
    struct service_request_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/**
 * Encoding and decoding of service.Response.
 */
struct service_response_t *
service_response_new(
    void *workspace_p,
    size_t size);

int service_response_encode(
    struct service_response_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int service_response_decode(
    struct service_response_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void service_request_init(
    struct service_request_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct service_request_t *next_p);

void service_request_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct service_request_t *self_p);

void service_request_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct service_request_t *self_p);

void service_request_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct service_request_repeated_t *repeated_p);

void service_request_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct service_request_repeated_t *repeated_p);

void service_request_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct service_request_repeated_t *repeated_p);

void service_response_init(
    struct service_response_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct service_response_t *next_p);

void service_response_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct service_response_t *self_p);

void service_response_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct service_response_t *self_p);

void service_response_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct service_response_repeated_t *repeated_p);

void service_response_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct service_response_repeated_t *repeated_p);

void service_response_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct service_response_repeated_t *repeated_p);

#endif
