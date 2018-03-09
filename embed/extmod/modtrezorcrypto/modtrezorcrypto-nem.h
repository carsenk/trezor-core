/*
 * This file is part of the TREZOR project, https://trezor.io/
 *
 * Copyright (c) SatoshiLabs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "py/objstr.h"
#include "nem.h"

/// class Nem:
///     '''
///     NEM
///     '''
typedef struct _mp_obj_nem_t {
} mp_obj_nem_t;

STATIC const mp_obj_type_t mod_trezorcrypto_nem_type;

/// def __init__(self) -> None:
///     '''
///     Creates a hash context object.
///     '''
STATIC mp_obj_t mod_trezorcrypto_nem_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
//    mp_arg_check_num(n_args, n_kw, 0, 1, false);
    mp_obj_nem_t *o = m_new_obj(mp_obj_nem_t);
//    ripemd160_Init(&(o->ctx));
    // constructor called with bytes/str as first parameter
//    if (n_args == 1) {
//        mod_trezorcrypto_Ripemd160_update(MP_OBJ_FROM_PTR(o), args[0]);
//    }
    return MP_OBJ_FROM_PTR(o);
}

/// def validate_address(self, address, network: int) -> bool:
///     '''
///     Compute a nem address string from the HD node.
///     '''
STATIC mp_obj_t mod_trezorcrypto_nem_validate_address(mp_obj_t self, mp_obj_t address, mp_obj_t network) {
//    mp_obj_HDNode_t *o = MP_OBJ_TO_PTR(self);

    uint32_t n = mp_obj_get_int_truncated(network);

    return mp_obj_new_bool(nem_validate_address(address, n));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(mod_trezorcrypto_nem_validate_address_obj, mod_trezorcrypto_nem_validate_address);


STATIC const mp_rom_map_elem_t mod_trezorcrypto_nem_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_validate_address), MP_ROM_PTR(&mod_trezorcrypto_nem_validate_address_obj) },
};
STATIC MP_DEFINE_CONST_DICT(mod_trezorcrypto_nem_locals_dict, mod_trezorcrypto_nem_locals_dict_table);

STATIC const mp_obj_type_t mod_trezorcrypto_nem_type = {
    { &mp_type_type },
    .name = MP_QSTR_nem,
    .make_new = mod_trezorcrypto_nem_make_new,
    .locals_dict = (void*)&mod_trezorcrypto_nem_locals_dict,
};
