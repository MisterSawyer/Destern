#ifndef  DETERN_SINGLETON_H
#define DETERN_SINGLETON_H

#include <atomic>
#include <mutex>
#include <memory>

namespace dst
{
	template<class T>
	class Singleton
	{
	public:
		static T & Instance()
		{
			//https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf

			T * instanceRawPtr = m_instance.load(std::memory_order_acquire).get();
			if (instanceRawPtr != nullptr)return *instanceRawPtr;

			std::lock_guard<std::mutex> lock(m_mutex);

			instanceRawPtr = m_instance.load(std::memory_order_relaxed).get();
			if (instanceRawPtr != nullptr)return *instanceRawPtr;

			instanceRawPtr = new T();
			m_instance.store(std::shared_ptr<T>(instanceRawPtr), std::memory_order_release);
			
			return *instanceRawPtr;
		}
	private:
		Singleton() = default;
		virtual ~Singleton() = default;

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;

		static std::atomic<std::shared_ptr<T>> m_instance;
		static std::mutex m_mutex;
	};

	template <typename T>
	std::atomic<std::shared_ptr<T>> Singleton<T>::m_instance;

	template <typename T>
	std::mutex  Singleton<T>::m_mutex;

}

#endif // ! DETERN_SINGLETON_H
