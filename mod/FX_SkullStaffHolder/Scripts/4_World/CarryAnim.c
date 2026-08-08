// Heavy two-handed carry, reusing vanilla's barrel profile and pose.
modded class ModItemRegisterCallbacks
{
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterHeavy(pType, pBehavior);

		pType.AddItemInHandsProfileIK(
			"fx_skull_staff_holder",
			"dz/anims/workspaces/player/player_main/player_main_heavy.asi",
			pBehavior,
			"dz/anims/anm/player/ik/heavy/55galDrum.anm");
	}
}
