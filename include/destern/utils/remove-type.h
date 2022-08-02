#ifndef  DETERN_REMOVETYPE_H
#define DETERN_REMOVETYPE_H

#include "type-list.h"

namespace dst::utils
{
	template <class T, class Ins, class Outs>
	struct remove_type_impl;

	template <class T, class ...Outs>
	struct remove_type_impl<T, type_list<>, type_list<Outs...>>
	{
		using type = typename type_list<Outs...>;
	};

	template <class T, class ...Ins, class ...Outs>
	struct remove_type_impl<T, type_list<T, Ins...>, type_list<Outs...>>
	{
		using type = remove_type_impl<T, type_list<Ins...>, type_list<Outs...>>::type;
	};

	template <class T, class I, class ...Ins, class ...Outs>
	struct remove_type_impl<T, type_list<I, Ins...>, type_list<Outs...>>
	{
		using type = remove_type_impl<T, type_list<Ins...>, type_list<Outs..., I>>::type;
	};

	template <class T, class Ts>
	struct remove_type;

	template <class T, class ...Ts>
	struct remove_type<T, type_list<Ts...>>
	{
		using type = remove_type_impl<T, type_list<Ts...>, type_list<>>::type;
	};
}
#endif