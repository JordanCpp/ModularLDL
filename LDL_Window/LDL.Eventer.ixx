// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

export module LDL.Eventer;

import LDL.Events;
import LDL.RingBuffer;

export namespace LDL
{
	class Eventer
	{
	public:
		enum
		{
			MaxEvents = 128
		};

		Eventer() :
			_running(true),
			_queue(MaxEvents)
		{
		}

		bool Empty() const
		{
			return _queue.empty();
		}

		void Push(Event& event)
		{
			_queue.enqueue(event);
		}

		bool Pop(Event& event)
		{
			if (!_queue.empty())
			{
				_queue.dequeue(event);

				return true;
			}

			return false;
		}

		bool Running() const
		{
			return _running;
		}

		void Stop()
		{
			_running = false;
		}
	private:
		bool              _running;
		RingBuffer<Event> _queue;
	};
}