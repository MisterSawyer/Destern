#ifndef  DETERN_OBJECT_H
#define DETERN_OBJECT_H

namespace dst
{
	class Object
	{
	public:
		virtual ~Object() = 0;
	};
	inline Object::~Object() {}
}

#endif