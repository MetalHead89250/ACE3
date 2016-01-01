
class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class GVAR(place) {
                displayName = CSTRING(DeploySandbag);
                condition = QUOTE(_this call FUNC(canDeploy));
                //wait a frame to handle "Do When releasing action menu key" option
                statement = QUOTE([ARR_2({_this call FUNC(deploy)},_this)] call EFUNC(common,execNextFrame));
                exceptions[] = {"isNotSwimming"};
                showDisabled = 0;
                priority = 4;
                icon = PATHTOF(UI\icon_sandbag_ca.paa);
            };
        };
    };

    class Item_Base_F;
    class ACE_Item_Sandbag_empty: Item_Base_F {
        author = ECSTRING(common,ACETeam);
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(sandbagEmpty_displayName);
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(ACE_Sandbag_empty,1);
        };
    };

    /*class ACE_Item_Sandbag: Item_Base_F {
        author = ECSTRING(common,ACETeam);
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(sandbag_displayName);
        vehicleClass = "Items";
        class TransportItems {
            class ACE_Sandbag {
                name = "ACE_Sandbag";
                count = 1;
            };
        };
    };*/

    class thingX;
    class ACE_SandbagObject: thingX {
        author = ECSTRING(common,ACETeam);
        XEH_ENABLED;
        scope = 2;
        side = -1;
        model = PATHTOF(data\ace_sandbag_build.p3d);
        displayName = CSTRING(sandbag_displayName);
        vehicleClass = "Objects";
        typicalCargo[] = {};
        armor = 12000; // Withstand 200 5.56 bullets before sandbag hull is cheese
        mapSize = 0.4;
        nameSound = "Bunker";
        icon = PATHTOF(UI\icon_sandbag_ca.paa);
        accuracy = 1000;
        destrType = "DestructDefault";

        class DestructionEffects {};

        class Damage {
            tex[] = {};
            mat[] = {
                "z\ace\addons\sandbag\data\bag_destruct.rvmat",
                "z\ace\addons\sandbag\data\bag_destruct.rvmat",
                "z\ace\addons\sandbag\data\bag_destruct.rvmat"
            };
        };

        class ACE_Actions {
            class ACE_MainActions {
                selection = "";
                distance = 5;
                condition = "true";

                class ACE_PickUp {
                    selection = "";
                    displayName = CSTRING(PICKUPSB);
                    distance = 4;
                    condition = QUOTE(!(_player getVariable [ARR_2(QUOTE(QGVAR(isUsingSandbag)),false)]));
                    statement = QUOTE([ARR_2(_player,_target)] call FUNC(pickup));
                    showDisabled = 0;
                    exceptions[] = {};
                    priority = 5;
                    icon = PATHTOF(UI\icon_sandbag_ca.paa);
                };
            };
        };
    };

    class ACE_SandbagObject_NoGeo: ACE_SandbagObject {
        scope = 1;
        model = PATHTOF(data\ace_sandbag_nogeo.p3d);
    };

    class Box_NATO_Support_F;
    class ACE_Box_Misc: Box_NATO_Support_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_Sandbag_empty,50);
        };
    };
};
