#pragma once

void DoPatches();

namespace SeedPacketsDefs
{
    // ---------- Adventure ----------
    namespace Peashooter     { constexpr uintptr_t SunCost = 0x69F2C0; constexpr uintptr_t Recharge = 0x69F2C4; } // 100 / 750
    namespace Sunflower      { constexpr uintptr_t SunCost = 0x69F2E4; constexpr uintptr_t Recharge = 0x69F2E8; } // 50 / 750
    namespace CherryBomb     { constexpr uintptr_t SunCost = 0x69F308; constexpr uintptr_t Recharge = 0x69F30C; } // 150 / 5000
    namespace WallNut        { constexpr uintptr_t SunCost = 0x69F32C; constexpr uintptr_t Recharge = 0x69F330; } // 50 / 3000
    namespace PotatoMine     { constexpr uintptr_t SunCost = 0x69F350; constexpr uintptr_t Recharge = 0x69F354; } // 25 / 3000
    namespace SnowPea        { constexpr uintptr_t SunCost = 0x69F374; constexpr uintptr_t Recharge = 0x69F378; } // 175 / 750
    namespace Chomper        { constexpr uintptr_t SunCost = 0x69F398; constexpr uintptr_t Recharge = 0x69F39C; } // 150 / 750
    namespace Repeater       { constexpr uintptr_t SunCost = 0x69F3BC; constexpr uintptr_t Recharge = 0x69F3C0; } // 200 / 750
    namespace PuffShroom     { constexpr uintptr_t SunCost = 0x69F3E0; constexpr uintptr_t Recharge = 0x69F3E4; } // 0 / 750
    namespace SunShroom      { constexpr uintptr_t SunCost = 0x69F404; constexpr uintptr_t Recharge = 0x69F408; } // 25 / 750
    namespace FumeShroom     { constexpr uintptr_t SunCost = 0x69F428; constexpr uintptr_t Recharge = 0x69F42C; } // 75 / 750
    namespace GraveBuster    { constexpr uintptr_t SunCost = 0x69F44C; constexpr uintptr_t Recharge = 0x69F450; } // 75 / 750
    namespace HypnoShroom    { constexpr uintptr_t SunCost = 0x69F470; constexpr uintptr_t Recharge = 0x69F474; } // 75 / 3000
    namespace ScaredyShroom  { constexpr uintptr_t SunCost = 0x69F494; constexpr uintptr_t Recharge = 0x69F498; } // 25 / 750
    namespace IceShroom      { constexpr uintptr_t SunCost = 0x69F4B8; constexpr uintptr_t Recharge = 0x69F4BC; } // 75 / 5000
    namespace DoomShroom     { constexpr uintptr_t SunCost = 0x69F4DC; constexpr uintptr_t Recharge = 0x69F4E0; } // 125 / 5000
    namespace LilyPad        { constexpr uintptr_t SunCost = 0x69F500; constexpr uintptr_t Recharge = 0x69F504; } // 25 / 750
    namespace Squash         { constexpr uintptr_t SunCost = 0x69F524; constexpr uintptr_t Recharge = 0x69F528; } // 50 / 3000
    namespace Threepeater    { constexpr uintptr_t SunCost = 0x69F548; constexpr uintptr_t Recharge = 0x69F54C; } // 325 / 750
    namespace TangleKelp     { constexpr uintptr_t SunCost = 0x69F56C; constexpr uintptr_t Recharge = 0x69F570; } // 25 / 3000
    namespace Jalapeno       { constexpr uintptr_t SunCost = 0x69F590; constexpr uintptr_t Recharge = 0x69F594; } // 125 / 5000
    namespace Spikeweed      { constexpr uintptr_t SunCost = 0x69F5B4; constexpr uintptr_t Recharge = 0x69F5B8; } // 100 / 750
    namespace TorchWood      { constexpr uintptr_t SunCost = 0x69F5D8; constexpr uintptr_t Recharge = 0x69F5DC; } // 175 / 750
    namespace TallNut        { constexpr uintptr_t SunCost = 0x69F5FC; constexpr uintptr_t Recharge = 0x69F600; } // 125 / 3000
 
    // ---------- Sea Shroom column ----------
    namespace SeaShroom      { constexpr uintptr_t SunCost = 0x69F620; constexpr uintptr_t Recharge = 0x69F624; } // 0 / 3000
    namespace Plantern       { constexpr uintptr_t SunCost = 0x69F644; constexpr uintptr_t Recharge = 0x69F648; } // 25 / 3000
    namespace Cactus         { constexpr uintptr_t SunCost = 0x69F668; constexpr uintptr_t Recharge = 0x69F66C; } // 125 / 750
    namespace Blover         { constexpr uintptr_t SunCost = 0x69F68C; constexpr uintptr_t Recharge = 0x69F690; } // 100 / 750
    namespace SplitPea       { constexpr uintptr_t SunCost = 0x69F6B0; constexpr uintptr_t Recharge = 0x69F6B4; } // 125 / 750
    namespace Starfruit      { constexpr uintptr_t SunCost = 0x69F6D4; constexpr uintptr_t Recharge = 0x69F6D8; } // 125 / 750
    namespace Pumpkin        { constexpr uintptr_t SunCost = 0x69F6F8; constexpr uintptr_t Recharge = 0x69F6FC; } // 125 / 750
    namespace MagnetShroom   { constexpr uintptr_t SunCost = 0x69F71C; constexpr uintptr_t Recharge = 0x69F720; } // 100 / 750
    namespace CabbagePult    { constexpr uintptr_t SunCost = 0x69F740; constexpr uintptr_t Recharge = 0x69F744; } // 100 / 750
    namespace FlowerPot      { constexpr uintptr_t SunCost = 0x69F764; constexpr uintptr_t Recharge = 0x69F768; } // 25 / 750
    namespace KernelPult     { constexpr uintptr_t SunCost = 0x69F788; constexpr uintptr_t Recharge = 0x69F78C; } // 100 / 750
    namespace CoffeeBean     { constexpr uintptr_t SunCost = 0x69F7AC; constexpr uintptr_t Recharge = 0x69F7B0; } // 75 / 750
    namespace Garlic         { constexpr uintptr_t SunCost = 0x69F7D0; constexpr uintptr_t Recharge = 0x69F7D4; } // 50 / 750
    namespace UmbrellaLeaf   { constexpr uintptr_t SunCost = 0x69F7F4; constexpr uintptr_t Recharge = 0x69F7F8; } // 100 / 750
    namespace Marigold       { constexpr uintptr_t SunCost = 0x69F818; constexpr uintptr_t Recharge = 0x69F81C; } // 50 / 3000
    namespace MelonPult      { constexpr uintptr_t SunCost = 0x69F83C; constexpr uintptr_t Recharge = 0x69F840; } // 300 / 750
    namespace GatlingPea     { constexpr uintptr_t SunCost = 0x69F860; constexpr uintptr_t Recharge = 0x69F864; } // 250 / 5000
    namespace TwinSunflower  { constexpr uintptr_t SunCost = 0x69F884; constexpr uintptr_t Recharge = 0x69F888; } // 150 / 5000
    namespace GloomShroom    { constexpr uintptr_t SunCost = 0x69F8A8; constexpr uintptr_t Recharge = 0x69F8AC; } // 150 / 5000
    namespace Cattail        { constexpr uintptr_t SunCost = 0x69F8CC; constexpr uintptr_t Recharge = 0x69F8D0; } // 225 / 5000
    namespace WinterMelon    { constexpr uintptr_t SunCost = 0x69F8F0; constexpr uintptr_t Recharge = 0x69F8F4; } // 200 / 5000
    namespace GoldMagnet     { constexpr uintptr_t SunCost = 0x69F914; constexpr uintptr_t Recharge = 0x69F918; } // 50 / 5000
    namespace Spikerock      { constexpr uintptr_t SunCost = 0x69F938; constexpr uintptr_t Recharge = 0x69F93C; } // 125 / 5000
    namespace CobCannon      { constexpr uintptr_t SunCost = 0x69F95C; constexpr uintptr_t Recharge = 0x69F960; } // 500 / 5000
    namespace Imitater       { constexpr uintptr_t SunCost = 0x69F980; constexpr uintptr_t Recharge = 0x69F984; } // 0 / 750
}



namespace ActionRatesDefinitions
{
    constexpr uintptr_t Peashooter_FireRate               = 0x69F2CC; // 150
    constexpr uintptr_t Sunflower_ProductionRate          = 0x69F2F0; // 2500
    constexpr uintptr_t CherryBombJalapeno_ExplosionDelay = 0x45E300; // 100
    constexpr uintptr_t PotatoMine_SurfacingTime          = 0x45E34E; // 1500
    constexpr uintptr_t SnowPea_FireRate                  = 0x69F380; // 150
    constexpr uintptr_t Chomper_ChewTime                  = 0x461551; // 4000
    constexpr uintptr_t Chomper_BiteSpeed                 = 0x4613BC; // 90
    constexpr uintptr_t Repeater_FireRate                 = 0x69F3C8; // 150
    constexpr uintptr_t PuffShroom_FireRate               = 0x69F3EC; // 150
    constexpr uintptr_t SunShroom_ProductionRate          = 0x69F410; // 2500
    constexpr uintptr_t SunShroom_GrowTime                = 0x45E3F1; // 12000
    constexpr uintptr_t FumeShroom_FireRate               = 0x69F434; // 150
    constexpr uintptr_t GraveBuster_Timer                 = 0x45FCE3; // 400
    constexpr uintptr_t ScaredyShroom_FireRate            = 0x69F4A0; // 150
    constexpr uintptr_t IceShroom_ExplosionDelay          = 0x4632B0; // 100
    constexpr uintptr_t DoomShroom_ExplosionDelay         = 0x460DFE; // 100
    constexpr uintptr_t DoomShroom_CraterLeavingTime      = 0x466887; // 18000
    constexpr uintptr_t Threepeater_FireRate              = 0x69F554; // 150
    // Spikeweed attack rate: 100 is default; fastest before it becomes
    // unable to attack is 76.
    constexpr uintptr_t Spikeweed_AttackRate              = 0x460361; // 100 (min stable: 76)
    constexpr uintptr_t SeaShroom_FireRate                = 0x69F62C; // 150
    constexpr uintptr_t Cactus_FireRate                   = 0x69F674; // 150
    constexpr uintptr_t Blover_BlowTime                   = 0x45DC5F; // 200
    constexpr uintptr_t Fog_LeaveTime                     = 0x466644; // 4000
    constexpr uintptr_t SplitPea_FireRate                 = 0x69F6BC; // 150
    constexpr uintptr_t Starfruit_FireRate                = 0x69F6E0; // 150
    constexpr uintptr_t MagnetShroom_Cooldown             = 0x46163A; // 1500
    constexpr uintptr_t CabbagePult_FireRate              = 0x69F74C; // 300
    constexpr uintptr_t KernelPult_FireRate               = 0x69F794; // 300
    constexpr uintptr_t KernelPult_ButterThrowChance      = 0x45F1E1; // 4
    constexpr uintptr_t CoffeeBean_Delay                  = 0x45E521; // 100
    constexpr uintptr_t Marigold_ProductionRate           = 0x69F824; // 2500
    constexpr uintptr_t MelonPult_FireRate                = 0x69F848; // 300
    constexpr uintptr_t GatlingPea_FireRate               = 0x69F86C; // 150
    constexpr uintptr_t TwinSunflower_ProductionRate      = 0x69F890; // 2500
    constexpr uintptr_t GloomShroom_FireRate              = 0x69F8B4; // 200
    constexpr uintptr_t Cattail_FiringRate                = 0x69F8D8; // 150
    constexpr uintptr_t WinterMelon_FireRate              = 0x69F8FC; // 300
    constexpr uintptr_t GoldMagnet_Cooldown               = 0x462985; // 200
    constexpr uintptr_t CobCannon_FirstAmmoCooldown       = 0x45E560; // 500
    constexpr uintptr_t CobCannon_Cooldown                = 0x464D4D; // 3000
    constexpr uintptr_t Imitater_Delay                    = 0x45E2D9; // 200
    constexpr uintptr_t ReverseRepeater_FireRate          = 0x69FA1C; // 150

    // ---------- Zombies ----------
    // Pole Vaulter jump speed: no known static address; use Cheat Engine
    // pointer scanning instead (value changes dynamically per instance).
    constexpr uintptr_t DancingZombie_CallDelay           = 0x528885; // 150
    constexpr uintptr_t ZombieYeti_FleeTime               = 0x522978; // 1500
    constexpr uintptr_t BungeeZombie_StealDelay           = 0x525127; // 300
    constexpr uintptr_t CatapultZombie_FirstShot          = 0x525A28; // 300
    constexpr uintptr_t CatapultZombie_ThrowingRate       = 0x525B28; // 300
    constexpr uintptr_t PeashooterZombie_FiringRate       = 0x5275B2; // 150
    constexpr uintptr_t GatlingPeaZombie_FiringRate       = 0x527831; // 150
}

namespace DamageRangeDefinitions
{
    constexpr uintptr_t Pea_Damage                                    = 0x69F1C8; // 20
    constexpr uintptr_t CherryBombDoomShroomJalapenoCobCannon_Damage  = 0x532FDC; // 1800
    constexpr uintptr_t PotatoMine_Damage                             = 0x41D931; // 1800
    constexpr uintptr_t SnowPea_Damage                                = 0x69F1D4; // 20
    constexpr uintptr_t ChomperBite_Damage                            = 0x4614DD; // 40
    constexpr uintptr_t Spore_Damage                                  = 0x69F1F8; // 20
    constexpr uintptr_t FumeShroomSpikeweedGloomShroomSpikerock_Damage = 0x45EDEF; // 20
    constexpr uintptr_t IceShroom_Damage                              = 0x532493; // 20 (limit is 128)
    constexpr uintptr_t Squash_Damage                                 = 0x4607A9; // 1800
    constexpr uintptr_t FirePea_Damage                                = 0x69F210; // 40
    constexpr uintptr_t Spike_Damage                                  = 0x69F228; // 20
    constexpr uintptr_t Star_Damage                                   = 0x69F21C; // 20
    constexpr uintptr_t Cabbage_Damage                                = 0x69F1E0; // 40
    constexpr uintptr_t Kernel_Damage                                 = 0x69F240; // 20
    constexpr uintptr_t Butter_Damage                                 = 0x69F258; // 40
    constexpr uintptr_t Melon_Damage                                  = 0x69F1EC; // 80
    constexpr uintptr_t WinterMelon_Damage                            = 0x69F204; // 80
    // ---------- Zombies ----------
    constexpr uintptr_t ZombieBite_ToPlants_Damage                    = 0x52FCF3; // 36
    constexpr uintptr_t ZombieBite_ToZombies_Damage                   = 0x52FE14; // 4
    constexpr uintptr_t Basketball_Damage                             = 0x69F234; // 75
    constexpr uintptr_t GargantuarSmash_Damage                        = 0x45EC63;
    constexpr uintptr_t ZombotanyPea_Damage                           = 0x69F264; // 20
	//------ Miscellaneous ---------w
    constexpr uintptr_t Rake_Damage                                   = 0x44E7D6; // 1800
}

namespace HealthArmorDefinitions
{
    // ---------- Plants ----------
    constexpr uintptr_t BasicPlant_Health                = 0x45DC55; // 300
    constexpr uintptr_t WallNut_Health                   = 0x45E1A7; // 4000
    constexpr uintptr_t TallNut_Health                   = 0x45E215; // 8000
    constexpr uintptr_t Pumpkin_Health                   = 0x45E445; // 4000
    constexpr uintptr_t Garlic_Health                    = 0x45E242; // 400
    constexpr uintptr_t Spikerock_Health                 = 0x45E5C3; // 450
    constexpr uintptr_t ExplodeONut_Health               = 0x45E1BA; // 4000
    constexpr uintptr_t GiantWallNut_Health              = 0x45E207; // 4000

    // ---------- Zombies ----------
    constexpr uintptr_t BasicZombie_Health               = 0x5227BB; // 270
    constexpr uintptr_t ConeheadZombie_Armor             = 0x522892; // 370
    constexpr uintptr_t PoleVaultingZombie_Health        = 0x522CBF; // 500
    constexpr uintptr_t BucketheadZombie_Armor           = 0x522992; // 1100
    constexpr uintptr_t NewspaperZombie_Armor            = 0x52337D; // 150
    constexpr uintptr_t ScreenDoorZombie_Armor           = 0x522949; // 1100
    constexpr uintptr_t FootballZombie_Armor             = 0x522BB0; // 1400
    constexpr uintptr_t DancingZombie_Health             = 0x523530; // 500
    constexpr uintptr_t Zomboni_Health                   = 0x522DE1; // 1350
    constexpr uintptr_t BobsledZombie_Health             = 0x523139; // 300
    constexpr uintptr_t DolphinRiderZombie_Health        = 0x522D64; // 500
    constexpr uintptr_t JackInTheBoxZombie_Health        = 0x522FC7; // 500
    constexpr uintptr_t BalloonZombie_Balloon            = 0x5234BF; // 20
    constexpr uintptr_t DiggerZombie_Armor               = 0x522BEF; // 100
    constexpr uintptr_t PogoZombie_Health                = 0x523300; // 500
    constexpr uintptr_t ZombieYeti_Health                = 0x52296E; // 1350
    constexpr uintptr_t BungeeZombie_Health              = 0x522A1B; // 450
    constexpr uintptr_t LadderZombie_ArmorAndHealth      = 0x52299C; // 500
    constexpr uintptr_t CatapultZombie_Health            = 0x522E8D; // 850
    constexpr uintptr_t Gargantuar_Health                = 0x523D26; // 3000
    constexpr uintptr_t ImpZombie_Health                 = 0x5235AC; // 70
    constexpr uintptr_t DrZomboss_Health                 = 0x523624; // 40000
    constexpr uintptr_t DrZomboss_ExtraHealthMinigames   = 0x52361E; // 20000
    constexpr uintptr_t WallNutZombie_Health             = 0x52382B; // 1100
    constexpr uintptr_t JalapenoZombie_Health            = 0x523A87; // 1100
    constexpr uintptr_t TallNutZombie_Health             = 0x52395D; // 2200
    constexpr uintptr_t GigaGargantuar_Health            = 0x523E4A; // 6000

    // Not confirmed accurate per the source table.
    constexpr uintptr_t IZombie_BrainHealth_NotAccurate  = 0x42A8DF; // 70
}