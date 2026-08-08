class fx_skull_staff_holder extends DeployableContainer_Base
{
	override bool IsDeployable()
	{
		return true;
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	// Carrying it off with the staff on would defeat the point of the holder.
	override bool CanPutIntoHands(EntityAI parent)
	{
		if (!super.CanPutIntoHands(parent))
			return false;

		return GetInventory() && GetInventory().AttachmentCount() == 0;
	}

	// SRP_Melee1 is shared by every SRP melee weapon, so the slot alone is too broad.
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		return attachment && attachment.IsKindOf("SRP_Staff_Skull_ColorBase");
	}
}
