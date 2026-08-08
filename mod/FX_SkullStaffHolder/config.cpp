class CfgPatches
{
    class FX_SkullStaffHolder
    {
        units[] = {"fx_skull_staff_holder"};
        weapons[] = {};
        requiredVersion = 0.1;
        // Survivalists_Weapons_JMC_Proxy declares Slot_SRP_Melee1.
        requiredAddons[] = {"DZ_Data", "Survivalists_Weapons_JMC_Proxy"};
    };
};

class CfgVehicles
{
    class Container_Base;

    // Deer Isle made SRP_Staff_Skull_Basic 11x11, past the inventory's 10 column limit, and
    // blocked storing clothing it is attached to. Their CanPutAsAttachment only refuses when
    // the parent is already in cargo, and their CanPutInCargo is on Clothing, so a holder you
    // attach to on the ground avoids both.
    //
    // Container_Base config side, DeployableContainer_Base script side, as SeaChest does.
    class fx_skull_staff_holder : Container_Base
    {
        scope = 2;
        displayName = "Staff Holder";
        descriptionShort = "A stone stand for a mystic staff.";
        model = "\projects\fx-skull-staff-holder\mod\FX_SkullStaffHolder\data\staffholder.p3d";
        // heavyItem = force hands-only carry.
        heavyItem = 1;
        itemBehaviour = 0;
        weight = 40000;
        itemSize[] = {6, 6};
        physLayer = "item_large";
        carveNavmesh = 1;
        slopeTolerance = 0.4;
        yawPitchRollLimit[] = {45, 45, 45};
        rotationFlags = 2;
        attachments[] = {"SRP_Melee1"};
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;

    // Binds the proxy in staffholder.p3d to the slot that feeds it.
    class ProxyStaffSkullProx : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = {"SRP_Melee1"};
        model = "\projects\fx-skull-staff-holder\mod\FX_SkullStaffHolder\data\staffskullprox.p3d";
    };
};

class CfgMods
{
    class FX_SkullStaffHolder
    {
        dir = "FX_SkullStaffHolder";
        name = "FX_SkullStaffHolder";
        credits = "";
        author = "";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"projects/fx-skull-staff-holder/mod/FX_SkullStaffHolder/Scripts/4_World"};
            };
        };
    };
};
