class CfgPatches
{
    class BlockInventory
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class BlockInventory
    {
        dir = "Blockinventory";
        name = "BlockInventory";
	    picture = "";
        action = "";
        hideName = 0;
        hidePicture = 1;
        author = "HF";
        version = "1.0";
        type = "mod";
        dependencies[] = {"World", "Mission"};

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"zhfbrpack/BlockInventory/scripts/4_World"};
			};
			class missionScriptModule
            {
                value = "";
                files[] = {"zhfbrpack/BlockInventory/scripts/5_Mission"};
			};
		};
    };
};