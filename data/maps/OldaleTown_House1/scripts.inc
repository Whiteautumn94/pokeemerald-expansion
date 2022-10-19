.set LOCALID_Eevee_BALL, 1

OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	msgbox OldaleTown_House1_Text_LeftPokemonGoesOutFirst, MSGBOX_NPC
	end

OldaleTown_House1_Text_LeftPokemonGoesOutFirst:
	.string "When a POKéMON battle starts, the one\n"
	.string "at the left of the list goes out first.\p"
	.string "So, when you get more POKéMON in your\n"
	.string "party, try switching around the order\l"
	.string "of your POKéMON.\p"
	.string "It could give you an advantage.$"


OlddaleTown_House1_EventScript_GiveEevee::
    setvar VAR_TEMP_1, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 15
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, OlddaleTown_House1_EventScript_SendEeveeParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, OlddaleTown_House1_EventScript_SendEeveePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

    OlddaleTown_House1_EventScript_SendEeveeParty::
	call OlddaleTown_House1_EventScript_ReceivedEeveeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlddaleTown_House1_EventScript_ReceivedEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto OlddaleTown_House1_EventScript_ReceivedEevee
	end

OlddaleTown_House1_EventScript_SendEeveePC::
	call OlddaleTown_House1_EventScript_ReceivedEeveeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlddaleTown_House1_EventScript_EeveeTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto OlddaleTown_House1_EventScript_EeveeTransferredToPC
	end

OlddaleTown_House1_EventScript_EeveeTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto OlddaleTown_House1_EventScript_ReceivedEevee
	end

OlddaleTown_House1_EventScript_ReceivedEeveeFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE
	removeobject LOCALID_Eevee_BALL
	playfanfare MUS_OBTAIN_ITEM
	message OlddaleTown_House1_Text_ObtainedEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	return

OlddaleTown_House1_EventScript_ReceivedEevee::
    setflag FLAG_RECEIVED_Eevee
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_Eevee_POKEBALL
    releaseall
	end

	OlddaleTown_House1_Text_TakeBallContainingEevee:
	.string "{PLAYER} checked the POKé BALL.\p"
	.string "It contained the POKéMON\n"
	.string "EEVEE.\p"
	.string "Take the POKé BALL?$"

    OlddaleTown_House1_Text_ObtainedEevee:
	.string "{PLAYER} obtained a EEVEE.$"

    OlddaleTown_House1_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} left the POKé BALL where\n"
	.string "it was.$"
