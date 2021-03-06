--
-- File generated with SQLiteStudio v3.1.0 on Wed Mar 8 11:57:20 2017
--
-- Text encoding used: System
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: weapon
CREATE TABLE weapon (WEAPON_ID INT PRIMARY KEY, NAME TEXT, ZONE STRING, "ACTION" STRING, DURABILITY INT);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('BB1', 'Broom', 'Bedroom', 'Swing', 2);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('BD1', 'DeskLamp', 'Bedroom', 'Throw', 1);

INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('EF1', 'FlashLight', 'Entrance', 'Swing', 2);

INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('HF1', 'FireExtinguisher', 'Hallway', 'Swing', 5);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('HP1', 'PictureFrame', 'Hallway', 'Throw', 4);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('HV1', 'Vase', 'Hallway', 'Throw', 4);

INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('MW1', 'Wrench', 'Maintenance room', 'Swing', 5);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('MS1', 'ScrewDriver', 'Maintenance room', 'Stab', 5);

INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('KK1', 'Knife', 'Kitchen', 'Stab', 5);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('KF1', 'FryingPan', 'Kitchen', 'Swing', 3);

INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('SS1', 'Sword', 'Study', 'Swing', 5);
INSERT INTO weapon (WEAPON_ID, NAME, ZONE, "ACTION", DURABILITY) VALUES ('SH1', 'HandGun', 'Study', 'Swing', 12);

-- Table: enemy
CREATE TABLE enemy (ENEMY_ID PRIMARY KEY, ENEMY_HP INT,ENEMY_ATK INT, ZONE STRING);
INSERT INTO enemy (ENEMY_ID, ENEMY_HP, ENEMY_ATK, ZONE) VALUES ('Weekened Zombie', 5, 2, 'Bedroom');
INSERT INTO enemy (ENEMY_ID, ENEMY_HP,ENEMY_ATK, ZONE) VALUES ('Rat', 3, 1, 'Hallway');
INSERT INTO enemy (ENEMY_ID, ENEMY_HP,ENEMY_ATK, ZONE) VALUES ('Bat', 5, 2, 'Hallway');
INSERT INTO enemy (ENEMY_ID, ENEMY_HP,ENEMY_ATK, ZONE) VALUES ('Zombie', 8, 3, 'Hallway');
INSERT INTO enemy (ENEMY_ID, ENEMY_HP,ENEMY_ATK, ZONE) VALUES ('Zombie General',50, 4, 'Study');
INSERT INTO enemy (ENEMY_ID, ENEMY_HP,ENEMY_ATK, ZONE) VALUES ('Zombie Elite', 12, 5, 'Kitchen');
INSERT INTO enemy (ENEMY_ID, ENEMY_HP,ENEMY_ATK, ZONE) VALUES ('Great Zombie General', 50, 6, 'Entrance');


-- Table: zone
CREATE TABLE zone (ZONE_ID STRING PRIMARY KEY, WEAPON REFERENCES weapon(NAME), ENEMY REFERENCES enemy(ENEMY_ID));
INSERT INTO zone (ZONE_ID, WEAPON, ENEMY) VALUES ('Study', (SELECT NAME FROM weapon WHERE ZONE=='Study'), (SELECT ENEMY_ID FROM enemy WHERE ZONE=='Study'));
INSERT INTO zone (ZONE_ID, WEAPON, ENEMY) VALUES ('Kitchen', (SELECT NAME FROM weapon WHERE ZONE=='Kitchen'), (SELECT ENEMY_ID FROM enemy WHERE ZONE=='Kitchen'));
INSERT INTO zone (ZONE_ID, WEAPON, ENEMY) VALUES ('Maintenance Room', (SELECT NAME FROM weapon WHERE ZONE=='Maintenance Room'), (SELECT ENEMY_ID FROM enemy WHERE ZONE=='Maintenance Room'));
INSERT INTO zone (ZONE_ID, WEAPON, ENEMY) VALUES ('Hallway', (SELECT NAME FROM weapon WHERE ZONE=='Hallway'), (SELECT ENEMY_ID FROM enemy WHERE ZONE=='Hallway'));
INSERT INTO zone (ZONE_ID, WEAPON, ENEMY) VALUES ('Bedroom', (SELECT NAME FROM weapon WHERE ZONE=='Bedroom'), (SELECT ENEMY_ID FROM enemy WHERE ZONE=='Bedroom'));
INSERT INTO zone (ZONE_ID, WEAPON, ENEMY) VALUES ('Entrance', (SELECT NAME FROM weapon WHERE ZONE=='Entrance'), (SELECT ENEMY_ID FROM enemy WHERE ZONE=='Entrance'));

-- Table: user   
CREATE TABLE user (user_id VARCHAR PRIMARY KEY, progress, curr_zone REFERENCES zone (ZONE_ID));

-- Table: action
CREATE TABLE action (ACTION_ID PRIMARY KEY, DAMAGE INT);



COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
