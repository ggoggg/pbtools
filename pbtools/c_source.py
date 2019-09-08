from .parser import SCALAR_VALUE_TYPES
from .parser import camel_to_snake_case


HEADER_FMT = '''\
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

#ifndef {include_guard}
#define {include_guard}

#include "pbtools.h"

{types}
{declarations}
#endif
'''

SOURCE_FMT = '''\
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

#include "{header}"

{definitions}\
'''

MESSAGE_STRUCT_FMT = '''\
/**
 * Message {full_name}.
 */
{repeated_struct}

struct {name}_t {{
    struct pbtools_message_base_t base;
{members}\
}};
'''

MESSAGE_DECLARATION_FMT = '''\
/**
 * Create a new message {proto_name} in given workspace.
 *
 * @param[in] workspace_p Message workspace.
 * @param[in] size Workspace size.
 *
 * @return Initialized address book, or NULL on failure.
 */
struct {name}_t *
{name}_new(
    void *workspace_p,
    size_t size);

/**
 * Encode message {proto_name} defined in package {package}.
 *
 * @param[in] self_p Message to encode.
 * @param[out] encoded_p Buffer to encode the message into.
 * @param[in] size Encoded buffer size.
 *
 * @return Encoded data length or negative error code.
 */
int {name}_encode(
    struct {name}_t *self_p,
    uint8_t *encoded_p,
    size_t size);

/**
 * Decode message {proto_name} defined in package {package}.
 *
 * @param[in,out] self_p Initialized message to decode into.
 * @param[in] encoded_p Buffer to decode.
 * @param[in] size Size of the encoded message.
 *
 * @return Number of bytes decoded or negative error code.
 */
int {name}_decode(
    struct {name}_t *self_p,
    const uint8_t *encoded_p,
    size_t size);
'''

MESSAGE_STATIC_DECLARATIONS_FMT = '''\
static void {name}_init(
    struct {name}_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct {name}_t *next_p);

static void {name}_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct {name}_t *self_p);

static void {name}_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct {name}_t *self_p);
'''

MESSAGE_STATIC_DEFINITIONS_FMT = '''\
static void {name}_init(
    struct {name}_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct {name}_t *next_p)
{{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
{members_init}
}}

static void {name}_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct {name}_t *self_p)
{{
{encode_body}\
}}

static void {name}_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct {name}_t *self_p)
{{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {{
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {{

{decode_body}
        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }}
    }}
{finalizers}\
}}
'''

ENCODE_INNER_MEMBER_FMT = '''\
    pbtools_encoder_write_{type}(encoder_p, {field_number}, {ref}self_p->{field_name});
'''

ENCODE_INNER_REPEATED_MEMBER_FMT = '''\
    pbtools_encoder_write_repeated_{type}(encoder_p, {field_number}, &self_p->{field_name});
'''

ENCODE_SUB_MESSAGE_MEMBER_FMT = '''\
    pbtools_encoder_sub_message_encode(
        encoder_p,
        {field_number},
        &self_p->{field_name}.base,
        (pbtools_message_encode_inner_t){type}_encode_inner);
'''

ENCODE_ENUM_FMT = '''\
    pbtools_encoder_write_enum(encoder_p, {field_number}, self_p->{field_name});
'''

ENCODE_INNER_REPEATED_MESSAGE_MEMBER_FMT = '''\
    {type}_encode_repeated_inner(
        encoder_p,
        {field_number},
        &self_p->{field_name});
'''

DECODE_INNER_MEMBER_FMT = '''\
        case {field_number}:
            self_p->{field_name} = pbtools_decoder_read_{type}(decoder_p, wire_type);
            break;
'''

DECODE_INNER_MEMBER_BYTES_AND_STRING_FMT = '''\
        case {field_number}:
            pbtools_decoder_read_{type}(decoder_p, wire_type, &self_p->{field_name});
            break;
'''

DECODE_INNER_REPEATED_MEMBER_FMT = '''\
        case {field_number}:
            pbtools_decoder_read_repeated_{type}(
                decoder_p,
                wire_type,
                &self_p->{field_name});
            break;
'''

DECODE_INNER_REPEATED_MESSAGE_MEMBER_FMT = '''\
        case {field_number}:
            {full_type}_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->{field_name});
            break;
'''

DECODE_SUB_MESSAGE_MEMBER_FMT = '''\
        case {field_number}:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->{field_name}.base,
                (pbtools_message_decode_inner_t){full_type}_decode_inner);
            break;
'''

DECODE_ENUM_FMT = '''\
        case {field_number}:
            self_p->{field_name} = pbtools_decoder_read_enum(decoder_p, wire_type);
            break;
'''

MESSAGE_DEFINITION_FMT = '''\
{repeated}\
struct {name}_t *
{name}_new(
    void *workspace_p,
    size_t size)
{{
    return (pbtools_message_new(
        workspace_p,
        size,
        sizeof(struct {name}_t),
        (pbtools_message_init_t){name}_init));
}}

int {name}_encode(
    struct {name}_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{{
    return (pbtools_message_encode(
        &self_p->base,
        encoded_p,
        size,
        (pbtools_message_encode_inner_t){name}_encode_inner));
}}

int {name}_decode(
    struct {name}_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{{
    return (pbtools_message_decode(
        &self_p->base,
        encoded_p,
        size,
        (pbtools_message_decode_inner_t){name}_decode_inner));
}}
'''

REPEATED_STRUCT_FMT = '''\
struct {name}_repeated_t {{
    int length;
    struct {name}_t **items_pp;
    struct {name}_t *head_p;
    struct {name}_t *tail_p;
}};\
'''

REPEATED_DECLARATION_FMT = '''\
int {name}_{field_name}_alloc(
    struct {name}_t *self_p,
    int length);
'''

REPEATED_DEFINITION_FMT = '''\
int {name}_{field_name}_alloc(
    struct {name}_t *self_p,
    int length)
{{
    return (pbtools_alloc_repeated_{type}(
        &self_p->base,
        length,
        &self_p->{field_name}));
}}
'''

REPEATED_MESSAGE_DEFINITION_FMT = '''\
int {name}_{field_name}_alloc(
    struct {name}_t *self_p,
    int length)
{{
    int res;
    int i;
    struct {name}_t *items_p;

    res = -1;
    self_p->{field_name}.items_pp = pbtools_heap_alloc(
        self_p->base.heap_p,
        sizeof(items_p) * length);

    if (self_p->{field_name}.items_pp != NULL) {{
        items_p = pbtools_heap_alloc(self_p->base.heap_p, sizeof(*items_p) * length);

        if (items_p != NULL) {{
            for (i = 0; i < length; i++) {{
                {name}_init(
                    &items_p[i],
                    self_p->base.heap_p,
                    &items_p[i + 1]);
                self_p->{field_name}.items_pp[i] = &items_p[i];
            }}

            items_p[length - 1].base.next_p = NULL;
            self_p->{field_name}.length = length;
            self_p->{field_name}.head_p = &items_p[0];
            self_p->{field_name}.tail_p = &items_p[length - 1];
            res = 0;
        }}
    }}

    return (res);
}}

static void {name}_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct {name}_repeated_t *repeated_p)
{{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t){name}_encode_inner);
}}

static void {name}_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct {name}_repeated_t *repeated_p)
{{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct {name}_t),
        (pbtools_message_init_t){name}_init,
        (pbtools_message_decode_inner_t){name}_decode_inner);
}}

static void {name}_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct {name}_repeated_t *repeated_p)
{{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}}
'''

REPEATED_MESSAGE_STATIC_DECLARATIONS_FMT = '''\
static void {name}_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct {name}_repeated_t *repeated_p);

static void {name}_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct {name}_repeated_t *repeated_p);

static void {name}_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct {name}_repeated_t *repeated_p);
'''

REPEATED_FINALIZER_FMT = '''\
    pbtools_decoder_finalize_repeated_{type}(
        decoder_p,
        &self_p->{field_name});\
'''

REPEATED_MESSAGE_FINALIZER_FMT = '''\
    {name}_finalize_repeated_inner(
        decoder_p,
        &self_p->{field_name});\
'''

ENUM_FMT = '''\
/**
 * Enum {full_name}.
 */
enum {name}_e {{
{members}
}};
'''

ENUM_MEMBER_FMT = '''\
    {name}_{field_name}_e = {field_number}\
'''

ONEOF_FMT = '''\
/**
 * Oneof {full_name}.
 */
struct {full_name_snake_case}_oneof_t {{
    enum {full_name_snake_case}_choice_e choice;
    union {{
{members}
    }} value;
}};
'''


class Generator:

    def __init__(self, parsed, header_name):
        self.namespace = camel_to_snake_case(parsed.package)
        self.parsed = parsed
        self.header_name = header_name

    @property
    def messages(self):
        return self.parsed.messages

    @property
    def package(self):
        return self.parsed.package

    def generate_struct_member_fmt(self, type, name, type_kind):
        if type in ['int32', 'int64', 'uint32', 'uint64']:
            type = f'{type}_t'
        elif type in ['sint32', 'sint64']:
            type = f'{type[1:]}_t'
        elif type in ['fixed32', 'fixed64']:
            type = f'uint{type[5:]}_t'
        elif type in ['sfixed32', 'sfixed64']:
            type = f'int{type[6:]}_t'
        elif type in ['float', 'double', 'bool']:
            pass
        elif type in ['bytes', 'string']:
            type = f'struct pbtools_bytes_t'
        elif type_kind == 'enum':
            type = f'enum {type}_e'
        elif type_kind == 'message':
            type = f'struct {type}_t'

        return f'    {type} {name};'

    def generate_repeated_struct_member_fmt(self, type, name):
        if type in SCALAR_VALUE_TYPES:
            if type in ['sint32', 'sint64']:
                type = type[1:]
            elif type in ['fixed32', 'fixed64']:
                type = f'uint{type[5:]}'
            elif type in ['sfixed32', 'sfixed64']:
                type = f'int{type[6:]}'

            type = f'struct pbtools_repeated_{type}_t'
        else:
            type = f'struct {type}_repeated_t'

        return f'    {type} {name};'

    def generate_struct_members(self, message):
        members = []

        for field in message.fields:
            if field.repeated:
                member = self.generate_repeated_struct_member_fmt(
                    field.full_type_snake_case,
                    field.name)
            else:
                member = self.generate_struct_member_fmt(
                    field.full_type_snake_case,
                    field.name,
                    field.type_kind)

            members.append(member)

        for oneof in message.oneofs:
            type = f'{message.full_name_snake_case}_{oneof.name}_oneof_t'
            members.append(
                f'    struct {type} {oneof.name};')

        members = '\n'.join(members)

        if members:
            members += '\n'

        return members

    def generate_repeated_struct(self, message):
        return REPEATED_STRUCT_FMT.format(name=message.full_name_snake_case)

    def generate_enum_members(self, enum):
        return ',\n'.join([
            ENUM_MEMBER_FMT.format(name=enum.full_name_snake_case,
                                   field_name=field.name_snake_case,
                                   field_number=field.field_number)
            for field in enum.fields])

    def generate_enum_type(self, enum):
        return [
            ENUM_FMT.format(full_name=enum.full_name,
                            name=enum.full_name_snake_case,
                            members=self.generate_enum_members(enum))
        ]

    def generate_oneof_members(self, oneof):
        members = []

        for field in oneof.fields:
            member = self.generate_struct_member_fmt(
                field.full_type_snake_case,
                field.name,
                field.type_kind)
            members.append(f'    {member}')

        return '\n'.join(members)

    def generate_oneof_choices(self, oneof):
        members = [
            f'    {oneof.full_name_snake_case}_choice_none_e = 0'
        ]

        for i, field in enumerate(oneof.fields, 1):
            members.append(
                f'    {oneof.full_name_snake_case}_choice_{field.name_snake_case}_e = {i}')

        return ENUM_FMT.format(full_name=oneof.full_name,
                               name=f'{oneof.full_name_snake_case}_choice',
                               members=',\n'.join(members))

    def generate_oneof_type(self, oneof):
        types = [self.generate_oneof_choices(oneof)]
        types += [
            ONEOF_FMT.format(full_name=oneof.full_name,
                             full_name_snake_case=oneof.full_name_snake_case,
                             name=oneof.name,
                             members=self.generate_oneof_members(oneof))
        ]

        return ['\n'.join(types)]

    def generate_message_types(self, message):
        types = []

        for enum in message.enums:
            types += self.generate_enum_type(enum)

        for inner_message in message.messages:
            types += self.generate_message_types(inner_message)

        for oneof in message.oneofs:
            types += self.generate_oneof_type(oneof)

        types += [
            MESSAGE_STRUCT_FMT.format(
                full_name=message.full_name,
                name=message.full_name_snake_case,
                repeated_struct=self.generate_repeated_struct(message),
                members=self.generate_struct_members(message))
        ]

        return types

    def generate_types(self):
        types = []

        for enum in self.parsed.enums:
            types += self.generate_enum_type(enum)

        for message in self.messages:
            types += self.generate_message_types(message)

        return '\n'.join(types)

    def generate_declarations(self):
        declarations = []

        for message in self.messages:
            message_name = message.full_name_snake_case
            declarations += [
                REPEATED_DECLARATION_FMT.format(name=message_name,
                                                field_name=field.name_snake_case)
                for field in message.repeated_fields
            ] + [
                MESSAGE_DECLARATION_FMT.format(package=self.package,
                                               proto_name=message.name,
                                               name=message_name)
            ]

        return '\n'.join(declarations)

    def generate_message_encode_body(self, message):
        members = []
        message_name = message.full_name_snake_case

        for field in reversed(message.fields):
            if field.type in SCALAR_VALUE_TYPES:
                if field.repeated:
                    fmt = ENCODE_INNER_REPEATED_MEMBER_FMT
                else:
                    fmt = ENCODE_INNER_MEMBER_FMT
            else:
                if field.repeated:
                    fmt = ENCODE_INNER_REPEATED_MESSAGE_MEMBER_FMT
                elif field.type_kind == 'message':
                    fmt = ENCODE_SUB_MESSAGE_MEMBER_FMT
                else:
                    fmt = ENCODE_ENUM_FMT

            member = fmt.format(name=message_name,
                                type=field.full_type_snake_case,
                                field_number=field.field_number,
                                field_name=field.name,
                                ref='&' if field.type in ['bytes', 'string'] else '')

            members.append(member)

        return ''.join(members)

    def generate_message_decode_body(self, message):
        members = []

        for field in message.fields:
            if field.repeated:
                if field.type in SCALAR_VALUE_TYPES:
                    fmt = DECODE_INNER_REPEATED_MEMBER_FMT
                else:
                    fmt = DECODE_INNER_REPEATED_MESSAGE_MEMBER_FMT
            elif field.type in ['bytes', 'string']:
                fmt = DECODE_INNER_MEMBER_BYTES_AND_STRING_FMT
            elif field.type in SCALAR_VALUE_TYPES:
                fmt = DECODE_INNER_MEMBER_FMT
            elif field.type_kind == 'message':
                fmt = DECODE_SUB_MESSAGE_MEMBER_FMT
            else:
                fmt = DECODE_ENUM_FMT

            members.append(
                fmt.format(full_type=field.full_type_snake_case,
                           type=field.type,
                           name=message.full_name_snake_case,
                           field_name=field.name_snake_case,
                           field_number=field.field_number))

        return '\n'.join(members)

    def generate_message_members_init(self, message):
        members = []

        for field in message.fields:
            name = field.name

            if field.repeated:
                member = f'    self_p->{name}.length = 0;'
            elif field.type in ['bytes', 'string']:
                member = f'    pbtools_{field.type}_init(&self_p->{name});'
            elif field.type_kind == 'scalar-value-type':
                member = f'    self_p->{name} = 0;'
            elif field.type_kind == 'message':
                member = (f'    {field.full_type_snake_case}_init(&self_p->{name}, '
                          f'heap_p, NULL);')
            else:
                member = f'    self_p->{name} = 0;'

            members.append(member)

        return '\n'.join(members)

    def generate_repeated_definitions(self, message):
        members = []

        for field in message.repeated_fields:
            if field.type in SCALAR_VALUE_TYPES:
                fmt = REPEATED_DEFINITION_FMT
            else:
                fmt = REPEATED_MESSAGE_DEFINITION_FMT

            members.append(fmt.format(name=message.full_name_snake_case,
                                      field_name=field.name,
                                      type=field.type))

        if members:
            members.append('')

        return '\n'.join(members)

    def generate_repeated_finalizers(self, message):
        finalizers = []

        for field in message.repeated_fields:
            if field.type in SCALAR_VALUE_TYPES:
                fmt = REPEATED_FINALIZER_FMT
            else:
                fmt = REPEATED_MESSAGE_FINALIZER_FMT

            finalizers.append(fmt.format(name=message.full_name_snake_case,
                                         field_name=field.name,
                                         type=field.type))

        if finalizers:
            finalizers = [''] + finalizers + ['']

        return '\n'.join(finalizers)

    def generate_definitions(self):
        declarations = []
        definitions = []

        for message in self.messages:
            self.generate_message_definitions(message,
                                              declarations,
                                              definitions,
                                              public=True)

        return '\n'.join(declarations + definitions)

    def generate_message_definitions(self,
                                     message,
                                     declarations,
                                     definitions,
                                     public):
        message_name = message.full_name_snake_case
        declarations.append(
            MESSAGE_STATIC_DECLARATIONS_FMT.format(name=message_name))

        for field in message.repeated_fields:
            if field.type in SCALAR_VALUE_TYPES:
                continue

            declarations.append(
                REPEATED_MESSAGE_STATIC_DECLARATIONS_FMT.format(
                    name=message_name))

        for inner_message in message.messages:
            self.generate_message_definitions(inner_message,
                                              declarations,
                                              definitions,
                                              public=False)

        definitions.append(
            MESSAGE_STATIC_DEFINITIONS_FMT.format(
                name=message.full_name_snake_case,
                encode_body=self.generate_message_encode_body(message),
                decode_body=self.generate_message_decode_body(message),
                members_init=self.generate_message_members_init(message),
                finalizers=self.generate_repeated_finalizers(message)))

        if public:
            definitions.append(
                MESSAGE_DEFINITION_FMT.format(
                    package=self.package,
                    proto_name=message.name,
                    name=message.full_name_snake_case,
                    repeated=self.generate_repeated_definitions(message)))

    def generate(self):
        namespace_upper = self.namespace.upper()
        header = HEADER_FMT.format(namespace_upper=namespace_upper,
                                   include_guard='{}_H'.format(namespace_upper),
                                   types=self.generate_types(),
                                   declarations=self.generate_declarations())
        source = SOURCE_FMT.format(namespace_upper=namespace_upper,
                                   header=self.header_name,
                                   definitions=self.generate_definitions())

        return header, source


def generate(namespace, parsed, header_name):
    """Generate C source code from given parsed proto-file.

    """

    return Generator(parsed, header_name).generate()
