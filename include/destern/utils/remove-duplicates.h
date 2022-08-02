#ifndef  DETERN_REMOVEDUPLICATES_H
#define DETERN_REMOVEDUPLICATES_H

#include "remove-type.h"

namespace dst::utils
{
    template<class InputList, class OutputList>
    struct remove_duplicates_impl;

    template <typename ... Ts>
    struct remove_duplicates_impl<type_list<>, type_list<Ts ...>>
    {
        using type = type_list<Ts ... >;
    };

    template <typename I, typename ...Ins, typename ... Outs>
    struct remove_duplicates_impl<type_list<I, Ins...>, type_list<Outs ...>>
    {
        using type = remove_duplicates_impl<typename remove_type<I, type_list<Ins...>>::type, type_list<Outs..., I>>::type;
    };


    template <typename TypeList>
    struct remove_duplicates;

    template <typename ... Ts>
    struct remove_duplicates<type_list<Ts ...>>
    {
        using type = remove_duplicates_impl<type_list<Ts ...>, type_list<>>::type;
    };
}
#endif