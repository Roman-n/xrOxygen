#pragma once

namespace PAPI
{
	// refs
	struct ParticleEffect;
	struct PARTICLES_API ParticleAction
	{
		enum 
		{
			ALLOW_ROTATE = (1 << 1)
		};
		Flags32 m_Flags;
		PActionEnum type;	// Type field
		ParticleAction() : type(action_enum_force_dword) { m_Flags.zero(); }

		virtual void Execute(ParticleEffect *pe, const float dt, float& m_max) = 0;
		virtual void Transform(const Fmatrix& m) = 0;

		virtual void Load(IReader& F) = 0;
		virtual void Save(IWriter& F) = 0;
	};

	using PAVec = xr_vector<ParticleAction*>;
	using PAVecIt = PAVec::iterator;

	class ParticleActions
	{
		PAVec actions;
	public:
		ParticleActions() { actions.reserve(4); }
		~ParticleActions() { clear(); }

		void clear()
		{
			for (PAPI::ParticleAction* pAction : actions)
			{
				xr_delete(pAction);
			}

			actions.clear();
		}

		inline void append(ParticleAction* pa) { actions.push_back(pa); }
		inline bool empty() { return	actions.empty(); }
		inline PAVecIt begin() { return	actions.begin(); }
		inline PAVecIt end() { return actions.end(); }
		inline int size() { return int(actions.size()); }
		inline void resize(int cnt) { actions.resize(cnt); }
	};
};