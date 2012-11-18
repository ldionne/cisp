/**
 * Basic token definitions.
 */

#ifndef CISP_DETAIL_BASE_TOKENS_H
#define CISP_DETAIL_BASE_TOKENS_H

/* [[[cog

import cisp
import string

TOKENS = list(set(string.ascii_letters) | set(string.digits) | {'_'})

C_CPP_KEYWORDS = [
    '_Alignas', '_Alignof', '_Atomic', '_Bool', '_Complex', '_Generic',
    '_Imaginary', '_Noreturn', '_Static_assert', '_Thread_local',
    'alignas', 'alignof', 'and', 'and_eq', 'asm', 'auto',
    'bitand', 'bitor', 'bool', 'break',
    'case', 'catch', 'char', 'char16_t', 'char32_t', 'class', 'compl',
    'const', 'constexpr', 'const_cast', 'continue',
    'decltype', 'default', 'delete', 'do', 'double', 'dynamic_cast',
    'else', 'enum', 'explicit', 'export', 'extern',
    'false', 'final', 'float', 'for', 'friend',
    'goto',
    'if', 'inline', 'int',
    'long',
    'mutable',
    'namespace', 'new', 'noexcept', 'not', 'not_eq', 'nullptr',
    'operator', 'or', 'or_eq', 'override',
    'private', 'protected', 'public',
    'register', 'reinterpret_cast', 'restrict', 'return',
    'short', 'signed', 'sizeof', 'static', 'static_assert', 'static_cast',
    'struct', 'switch',
    'template', 'this', 'thread_local', 'throw', 'true', 'try', 'typedef',
    'typeid', 'typename',
    'union', 'unsigned', 'using',
    'virtual', 'void', 'volatile',
    'wchar_t', 'while',
    'xor', 'xor_eq',
]

cisp.generate_tokens(cog.outl, *list(TOKENS + C_CPP_KEYWORDS))

]]] */
#define CISP_TOKEN_1 (1)
#define CISP_TOKEN_0 (0)
#define CISP_TOKEN_3 (3)
#define CISP_TOKEN_2 (2)
#define CISP_TOKEN_5 (5)
#define CISP_TOKEN_4 (4)
#define CISP_TOKEN_7 (7)
#define CISP_TOKEN_6 (6)
#define CISP_TOKEN_9 (9)
#define CISP_TOKEN_8 (8)
#define CISP_TOKEN_A (A)
#define CISP_TOKEN_C (C)
#define CISP_TOKEN_B (B)
#define CISP_TOKEN_E (E)
#define CISP_TOKEN_D (D)
#define CISP_TOKEN_G (G)
#define CISP_TOKEN_F (F)
#define CISP_TOKEN_I (I)
#define CISP_TOKEN_H (H)
#define CISP_TOKEN_K (K)
#define CISP_TOKEN_J (J)
#define CISP_TOKEN_M (M)
#define CISP_TOKEN_L (L)
#define CISP_TOKEN_O (O)
#define CISP_TOKEN_N (N)
#define CISP_TOKEN_Q (Q)
#define CISP_TOKEN_P (P)
#define CISP_TOKEN_S (S)
#define CISP_TOKEN_R (R)
#define CISP_TOKEN_U (U)
#define CISP_TOKEN_T (T)
#define CISP_TOKEN_W (W)
#define CISP_TOKEN_V (V)
#define CISP_TOKEN_Y (Y)
#define CISP_TOKEN_X (X)
#define CISP_TOKEN_Z (Z)
#define CISP_TOKEN__ (_)
#define CISP_TOKEN_a (a)
#define CISP_TOKEN_c (c)
#define CISP_TOKEN_b (b)
#define CISP_TOKEN_e (e)
#define CISP_TOKEN_d (d)
#define CISP_TOKEN_g (g)
#define CISP_TOKEN_f (f)
#define CISP_TOKEN_i (i)
#define CISP_TOKEN_h (h)
#define CISP_TOKEN_k (k)
#define CISP_TOKEN_j (j)
#define CISP_TOKEN_m (m)
#define CISP_TOKEN_l (l)
#define CISP_TOKEN_o (o)
#define CISP_TOKEN_n (n)
#define CISP_TOKEN_q (q)
#define CISP_TOKEN_p (p)
#define CISP_TOKEN_s (s)
#define CISP_TOKEN_r (r)
#define CISP_TOKEN_u (u)
#define CISP_TOKEN_t (t)
#define CISP_TOKEN_w (w)
#define CISP_TOKEN_v (v)
#define CISP_TOKEN_y (y)
#define CISP_TOKEN_x (x)
#define CISP_TOKEN_z (z)
#define CISP_TOKEN__Alignas (_ A l i g n a s)
#define CISP_TOKEN__Alignof (_ A l i g n o f)
#define CISP_TOKEN__Atomic (_ A t o m i c)
#define CISP_TOKEN__Bool (_ B o o l)
#define CISP_TOKEN__Complex (_ C o m p l e x)
#define CISP_TOKEN__Generic (_ G e n e r i c)
#define CISP_TOKEN__Imaginary (_ I m a g i n a r y)
#define CISP_TOKEN__Noreturn (_ N o r e t u r n)
#define CISP_TOKEN__Static_assert (_ S t a t i c _ a s s e r t)
#define CISP_TOKEN__Thread_local (_ T h r e a d _ l o c a l)
#define CISP_TOKEN_alignas (a l i g n a s)
#define CISP_TOKEN_alignof (a l i g n o f)
#define CISP_TOKEN_and (a n d)
#define CISP_TOKEN_and_eq (a n d _ e q)
#define CISP_TOKEN_asm (a s m)
#define CISP_TOKEN_auto (a u t o)
#define CISP_TOKEN_bitand (b i t a n d)
#define CISP_TOKEN_bitor (b i t o r)
#define CISP_TOKEN_bool (b o o l)
#define CISP_TOKEN_break (b r e a k)
#define CISP_TOKEN_case (c a s e)
#define CISP_TOKEN_catch (c a t c h)
#define CISP_TOKEN_char (c h a r)
#define CISP_TOKEN_char16_t (c h a r 1 6 _ t)
#define CISP_TOKEN_char32_t (c h a r 3 2 _ t)
#define CISP_TOKEN_class (c l a s s)
#define CISP_TOKEN_compl (c o m p l)
#define CISP_TOKEN_const (c o n s t)
#define CISP_TOKEN_constexpr (c o n s t e x p r)
#define CISP_TOKEN_const_cast (c o n s t _ c a s t)
#define CISP_TOKEN_continue (c o n t i n u e)
#define CISP_TOKEN_decltype (d e c l t y p e)
#define CISP_TOKEN_default (d e f a u l t)
#define CISP_TOKEN_delete (d e l e t e)
#define CISP_TOKEN_do (d o)
#define CISP_TOKEN_double (d o u b l e)
#define CISP_TOKEN_dynamic_cast (d y n a m i c _ c a s t)
#define CISP_TOKEN_else (e l s e)
#define CISP_TOKEN_enum (e n u m)
#define CISP_TOKEN_explicit (e x p l i c i t)
#define CISP_TOKEN_export (e x p o r t)
#define CISP_TOKEN_extern (e x t e r n)
#define CISP_TOKEN_false (f a l s e)
#define CISP_TOKEN_final (f i n a l)
#define CISP_TOKEN_float (f l o a t)
#define CISP_TOKEN_for (f o r)
#define CISP_TOKEN_friend (f r i e n d)
#define CISP_TOKEN_goto (g o t o)
#define CISP_TOKEN_if (i f)
#define CISP_TOKEN_inline (i n l i n e)
#define CISP_TOKEN_int (i n t)
#define CISP_TOKEN_long (l o n g)
#define CISP_TOKEN_mutable (m u t a b l e)
#define CISP_TOKEN_namespace (n a m e s p a c e)
#define CISP_TOKEN_new (n e w)
#define CISP_TOKEN_noexcept (n o e x c e p t)
#define CISP_TOKEN_not (n o t)
#define CISP_TOKEN_not_eq (n o t _ e q)
#define CISP_TOKEN_nullptr (n u l l p t r)
#define CISP_TOKEN_operator (o p e r a t o r)
#define CISP_TOKEN_or (o r)
#define CISP_TOKEN_or_eq (o r _ e q)
#define CISP_TOKEN_override (o v e r r i d e)
#define CISP_TOKEN_private (p r i v a t e)
#define CISP_TOKEN_protected (p r o t e c t e d)
#define CISP_TOKEN_public (p u b l i c)
#define CISP_TOKEN_register (r e g i s t e r)
#define CISP_TOKEN_reinterpret_cast (r e i n t e r p r e t _ c a s t)
#define CISP_TOKEN_restrict (r e s t r i c t)
#define CISP_TOKEN_return (r e t u r n)
#define CISP_TOKEN_short (s h o r t)
#define CISP_TOKEN_signed (s i g n e d)
#define CISP_TOKEN_sizeof (s i z e o f)
#define CISP_TOKEN_static (s t a t i c)
#define CISP_TOKEN_static_assert (s t a t i c _ a s s e r t)
#define CISP_TOKEN_static_cast (s t a t i c _ c a s t)
#define CISP_TOKEN_struct (s t r u c t)
#define CISP_TOKEN_switch (s w i t c h)
#define CISP_TOKEN_template (t e m p l a t e)
#define CISP_TOKEN_this (t h i s)
#define CISP_TOKEN_thread_local (t h r e a d _ l o c a l)
#define CISP_TOKEN_throw (t h r o w)
#define CISP_TOKEN_true (t r u e)
#define CISP_TOKEN_try (t r y)
#define CISP_TOKEN_typedef (t y p e d e f)
#define CISP_TOKEN_typeid (t y p e i d)
#define CISP_TOKEN_typename (t y p e n a m e)
#define CISP_TOKEN_union (u n i o n)
#define CISP_TOKEN_unsigned (u n s i g n e d)
#define CISP_TOKEN_using (u s i n g)
#define CISP_TOKEN_virtual (v i r t u a l)
#define CISP_TOKEN_void (v o i d)
#define CISP_TOKEN_volatile (v o l a t i l e)
#define CISP_TOKEN_wchar_t (w c h a r _ t)
#define CISP_TOKEN_while (w h i l e)
#define CISP_TOKEN_xor (x o r)
#define CISP_TOKEN_xor_eq (x o r _ e q)
/* [[[end]]] */

#endif /* !CISP_DETAIL_BASE_TOKENS_H */
