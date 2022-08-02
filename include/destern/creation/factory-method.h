#ifndef  DETERN_FACTORYMETHOD_H
#define DETERN_FACTORYMETHOD_H

#include <memory>
#include <type_traits>

namespace dst
{
	template<class Interface>
	class FactoryMethod
	{
	public:
		virtual ~FactoryMethod() = default;
		virtual std::unique_ptr<Interface> Create() const = 0;
	};
}

#endif