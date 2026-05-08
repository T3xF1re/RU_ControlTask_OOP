
#include "helpfulClassesAndFunctions.h"

//Mandatory classes

//Base class
#include "Game.h"

//First inheritor classes:
#include "SingleplayerGame.h"
#include "MultiplayerGame.h"

//Second inheritor classes
#include "Platformer.h"
#include "Sandbox.h"
#include "MOBA.h"
#include "Shooter.h"
#include "RPG.h"

//Third inheritor classes
#include "MMORPG.h"
#include "HeroShooter.h"


//arrays of data for different classes
const string platformerObstacles[] = { "quicksand", "swinging vines", "poison darts", "wild animals", "falling trees", "river currents", "hidden traps" };

const string sandboxMaterials[] = { "wood", "stone", "glass", "metal", "sand", "crystal" };
const string sandboxShapes[] = { "cube", "sphere", "pyramid", "cylinder", "cone" };

const string mobaCharacters[] = { "Celestial Knight", "Void Assassin", "Nature Guardian", "Storm Caller", "Blaze Warrior" };

const string shooterGear[] = { "assault rifle", "sniper rifle", "shotgun", "grenade launcher", "combat knife", "flashbang", "SMG", "rocket launcher", "pistol", "frag grenade", "body armor" };

const string rpgClasses[] = { "Dragon Slayer", "Elementalist", "Necromancer", "Paladin", "Ranger", "Berserker", "Druid", "Celestial Mage", "Alchemist" };
const string rpgCustomOptions[] = { "armor dyes", "weapon enchantments", "pet companions", "wings", "skill visuals", "banners", "helm styles", "voice packs" };

const string mmorpgClasses[] = { "Paladin", "Necromancer", "Ranger", "Sorcerer", "Berserker", "Cleric", "Assassin", "Druid" };
const string mmorpgCustomOptions[] = { "armor sets", "weapon enchantments", "mounts", "companions", "skill effects", "titles", "emotes" };
const string mmorpgNPCs[] = { "King Aldric", "Archmage Lyra", "Blacksmith Torven", "Merchant Selene", "Guard Captain Rurik", "Wandering Bard Elio" };

const string heroShooterCharacters[] = { "Rift Guardian", "Flamecaster", "Storm Ranger", "Void Assassin", "Lightbringer", "Stone Titan" };
const string heroShooterGear[] = { "arcane rifle", "flame gauntlets", "storm bow", "void daggers", "earth hammer", "phase blade", "healing injector", "gravity mines", "energy shield" };
const string heroShooterMonsters[] = { "rift beasts", "lava golems", "shadow fiends", "storm elementals", "void reapers" };


//all available genres
enum gameGenres
{
	_Platformer = 1,
	_Sandbox,
	_MOBA,
	_Shooter,
	_RPG,
	_MMORPG,
	_HeroShooter
};

//class that controls the interaction in the program
class Player
{
	int numberOfGames = 7;
	Game* games[10] = {
		new Platformer("Jungle Leap Legends", "PixelForge Studios", 14, 6, 2021, 1040813, 0.09, 4.2, 7, platformerObstacles, "Find the lost temple and recover the ancient relic.", 2450000, 48),
		new Sandbox("Blockiverse Creator", "NovaBuild Studios", 17, 2, 2023, 1050009, 1.3, 3.7, "Build and expand a limitless world using creative tools.", 6, sandboxMaterials, 5, sandboxShapes, 3567000),
		new MOBA("Mythic Nexus", "ArcLight Games", 29, 8, 2020, 1090000, 21.31, 4.1, 5, mobaCharacters, 98700, 275),
		new Shooter("Iron Strike Ops 2", "RedZone Interactive", 24, 1, 2023, 2010607, 4.19, 3.9, 11, shooterGear, 154300, 410),
		new RPG("Legends of Emberfall", "Dragonveil Interactive", 25, 8, 2021, 1011003, 128.26, 4.5, "Unite the shattered kingdoms and slay the Ember Dragon.", 9, rpgClasses, 8, rpgCustomOptions, 203500, 520, 1984000, 4),
		new MMORPG("Eternal Realms Online 2", "CelestiaWorks", 12, 4, 2019, 2000819, 140.31, 4.6, "Restore balance to the fractured realms and defeat the Ascended Void Lord.", 8, mmorpgClasses, 7, mmorpgCustomOptions, 6, mmorpgNPCs, 325400, 235, 3789000, 2),
		new HeroShooter("Legends of Riftfire", "QuantumCore Entertainment", 10, 11, 2024, 1070000, 20.98, 3.2, 6, heroShooterCharacters, 9, heroShooterGear, 5, heroShooterMonsters, 165800, 295, 2897000)
	};

	gameGenres chooseGenre();

public:
	void bootUp();
	const Game* downloadGame();
	void deleteGame(int pos);
	void openGame(int pos);
	void printAllGamesInfo();
 };