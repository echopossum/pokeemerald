Creator_House_MapScripts::
	.byte 0


CreatorHouse_EventScript_Pokeball::
# 4 "data/maps/Creator_House/scripts.pory"
	lockall
# 5 "data/maps/Creator_House/scripts.pory"
	showmonpic SPECIES_ARON, 10, 3
# 6 "data/maps/Creator_House/scripts.pory"
	msgbox CreatorHouse_EventScript_Pokeball_Text_0, MSGBOX_YESNO
# 7 "data/maps/Creator_House/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CreatorHouse_EventScript_Pokeball_2
# 29 "data/maps/Creator_House/scripts.pory"
	hidemonpic
# 30 "data/maps/Creator_House/scripts.pory"
	msgbox CreatorHouse_NotChosen
CreatorHouse_EventScript_Pokeball_1:
# 32 "data/maps/Creator_House/scripts.pory"
	waitmessage
# 33 "data/maps/Creator_House/scripts.pory"
	releaseall
	end

CreatorHouse_EventScript_Pokeball_2:
# 8 "data/maps/Creator_House/scripts.pory"
	givemon SPECIES_ARON, 50, ITEM_MASTER_BALL
# 9 "data/maps/Creator_House/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq CreatorHouse_EventScript_Pokeball_5
# 16 "data/maps/Creator_House/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq CreatorHouse_EventScript_Pokeball_6
# 24 "data/maps/Creator_House/scripts.pory"
	hidemonpic
# 25 "data/maps/Creator_House/scripts.pory"
	msgbox CreatorHouse_EventScript_Pokeball_Text_2
	goto CreatorHouse_EventScript_Pokeball_1

CreatorHouse_EventScript_Pokeball_5:
# 10 "data/maps/Creator_House/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 11 "data/maps/Creator_House/scripts.pory"
	msgbox CreatorHouse_EventScript_Pokeball_Text_1
# 12 "data/maps/Creator_House/scripts.pory"
	removeobject 1
# 13 "data/maps/Creator_House/scripts.pory"
	setflag LITTLEROOT_ARON
# 14 "data/maps/Creator_House/scripts.pory"
	call NicknamePartyMon
	goto CreatorHouse_EventScript_Pokeball_1

CreatorHouse_EventScript_Pokeball_6:
# 17 "data/maps/Creator_House/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 18 "data/maps/Creator_House/scripts.pory"
	msgbox CreatorHouse_EventScript_Pokeball_Text_1
# 19 "data/maps/Creator_House/scripts.pory"
	removeobject 1
# 20 "data/maps/Creator_House/scripts.pory"
	setflag LITTLEROOT_ARON
# 21 "data/maps/Creator_House/scripts.pory"
	call NicnameBoxMon
	goto CreatorHouse_EventScript_Pokeball_1


NicknamePartyMon::
# 38 "data/maps/Creator_House/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 39 "data/maps/Creator_House/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 40 "data/maps/Creator_House/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 41 "data/maps/Creator_House/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicnameBoxMon::
# 46 "data/maps/Creator_House/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 47 "data/maps/Creator_House/scripts.pory"
	hidemonpic
# 48 "data/maps/Creator_House/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicnameBoxMon_2
NicnameBoxMon_1:
# 51 "data/maps/Creator_House/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

NicnameBoxMon_2:
# 49 "data/maps/Creator_House/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicnameBoxMon_1


CreatorHouse_EventScript_Pokeball_Text_0:
# 6 "data/maps/Creator_House/scripts.pory"
	.string "Do you want to choose Aron?$"

CreatorHouse_EventScript_Pokeball_Text_1:
# 11 "data/maps/Creator_House/scripts.pory"
	.string "Received Aron$"

CreatorHouse_EventScript_Pokeball_Text_2:
# 25 "data/maps/Creator_House/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 38 "data/maps/Creator_House/scripts.pory"
	.string "Give it a nickname?$"

CreatorHouse_NotChosen::
# 54 "data/maps/Creator_House/scripts.pory"
	.string "You did not take the Aron$"
