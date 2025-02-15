#pragma	once
#include "physics_shell_animated.h"

class	CBlend;
struct	dContact;
struct	SGameMtl;

class XRPHYSICS_API interactive_animation : public CPhShellAnimated
{
	using inherited = CPhShellAnimated;
	CBlend *blend;
	
public:
	interactive_animation(CPhysicsShellHolder* ca, CBlend* b);
	virtual		~interactive_animation();

	virtual		bool update(const Fmatrix	&xrorm);

private:
	virtual		void create_shell(CPhysicsShellHolder* O);
				bool collide();
	static		void contact_callback(bool& do_colide, bool bo1, dContact& c, SGameMtl * /*material_1*/, SGameMtl * /*material_2*/);
};