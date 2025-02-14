namespace GOTHIC_NAMESPACE 
{
#if 1
	void __fastcall Npc_GetGuildAttitude(Union::Registers& reg);
	auto Partial_Npc_GetGuildAttitude =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x006545b9,
                        0x0,
                        0x0,
                        0x006e5da5)), &Npc_GetGuildAttitude);
	void __fastcall Npc_GetGuildAttitude(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If either of them is not valid we return ATT_NEUTRAL = 2
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if ((reg.edi == 0) || (reg.ebx == 0))
            parser->SetReturn(NPC_ATT_NEUTRAL);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)(*(DWORD*)(reg.esp + 0x18));
        if (reg.esi == 0 || (*(DWORD*)(reg.esp + 0x14) == 0))  {
            parser->SetReturn(NPC_ATT_NEUTRAL);
        }
#endif
    }


	void __fastcall Npc_HasDetectedNpc(Union::Registers& reg);
	auto Partial_Npc_HasDetectedNpc =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x006552ef,
                        0x0,
                        0x0,
                        0x006e8940)), &Npc_HasDetectedNpc);
	void __fastcall Npc_HasDetectedNpc(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If either of them is not valid we return false
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if ((reg.edi == 0) || (reg.eax == 0))
            parser->SetReturn(false);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)(*(DWORD*)(reg.esp + 0x18));
        if ((reg.esi == 0) || (*(DWORD*)(reg.esp + 0x14) == 0))
            parser->SetReturn(false);
#endif
	}

	void __fastcall Npc_GetAttitude(Union::Registers& reg);
	auto Partial_Npc_GetAttitude =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x006554af,
                        0x0,
                        0x0,
                        0x006e8ea0)), &Npc_GetAttitude);
	void __fastcall Npc_GetAttitude(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If either of them is not valid we return ATT_NEUTRAL = 2
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if ((reg.edi == 0) || (reg.eax == 0))
            parser->SetReturn(NPC_ATT_NEUTRAL);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)(*(DWORD*)(reg.esp + 0x18));
        if ((reg.esi == 0) || (*(DWORD*)(reg.esp + 0x14) == 0)) 
            parser->SetReturn(NPC_ATT_NEUTRAL);
#endif
	}


	void __fastcall Npc_GetPermAttitude(Union::Registers& reg);
	auto Partial_Npc_GetPermAttitude =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x0065551f,
                        0x0,
                        0x0,
                        0x006e9060)), &Npc_GetPermAttitude);
	void __fastcall Npc_GetPermAttitude(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If either of them is not valid we return ATT_NEUTRAL = 2
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if ((reg.edi == 0) || (reg.eax == 0))
            parser->SetReturn(NPC_ATT_NEUTRAL);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)(*(DWORD*)(reg.esp + 0x18));
        if ((reg.esi == 0) || (reg.esp == 0x3C))
            parser->SetReturn(NPC_ATT_NEUTRAL);
#endif
	}

	void __fastcall Npc_HasSpell(Union::Registers& reg);
	auto Partial_Npc_HasSpell =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x0065bfd1,
                        0x0,
                        0x0,
                        0x006f5a1f)), &Npc_HasSpell);
	void __fastcall Npc_HasSpell(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If either of them is not valid we return false
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if (reg.eax == 0)
            parser->SetReturn(false);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)reg.esi;
        if (reg.edi == 0)
            parser->SetReturn(false);
#endif
	}

	void __fastcall Npc_GetActiveSpell(Union::Registers& reg);
	auto Partial_Npc_GetActiveSpell =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x00654479,
                        0x0,
                        0x0,
                        0x006e5644)), &Npc_GetActiveSpell);
	void __fastcall Npc_GetActiveSpell(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If the parameter is not valid we return -1 (invalid spell)
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if (reg.eax == 0)
            parser->SetReturn(-1);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)reg.ebp;
        if (reg.esi == 0)
            parser->SetReturn(-1);
#endif
	}

	void __fastcall Npc_GetActiveSpellCat(Union::Registers& reg);
	auto Partial_Npc_GetActiveSpellCat =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x00654509,
                        0x0,
                        0x0,
                        0x006e5a24)), &Npc_GetActiveSpellCat);
	void __fastcall Npc_GetActiveSpellCat(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If the parameter is not valid we return -1 (invalid category)
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if (reg.eax == 0)
            parser->SetReturn(-1);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)reg.ebp;
        if (reg.esi == 0)
            parser->SetReturn(-1);
#endif
	}

	void __fastcall Npc_GetActiveSpellLevel(Union::Registers& reg);
	auto Partial_Npc_GetActiveSpellLevel =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x00654549,
                        0x0,
                        0x0,
                        0x006e5b04)), &Npc_GetActiveSpellLevel);
	void __fastcall Npc_GetActiveSpellLevel(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If the parameter is not valid we return -1 (invalid level)
#if ENGINE == 1
        zCParser* parser = (zCParser*)reg.esi;
        if (reg.eax == 0)
            parser->SetReturn(-1);
#elif ENGINE == 4
        zCParser* parser = (zCParser*)reg.ebp;
        if (reg.esi == 0)
            parser->SetReturn(-1);
#endif
	}

#if ENGINE > 2 // G2 and G2A
	void __fastcall Npc_GetActiveSpellIsScroll(Union::Registers& reg);
	auto Partial_Npc_GetActiveSpellIsScroll =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x0,
                        0x0,
                        0x0,
                        0x0006e5be4)), &Npc_GetActiveSpellIsScroll);
	void __fastcall Npc_GetActiveSpellIsScroll(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If the parameter is not valid we return false
        zCParser* parser = (zCParser*)reg.ebp;
        if (reg.esi == reg.ebx)
            parser->SetReturn(false);
	}

	void __fastcall Npc_GetGetLastHitSpellID(Union::Registers& reg);
	auto Partial_Npc_GetGetLastHitSpellID =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x0,
                        0x0,
                        0x0,
                        0x006e574c)), &Npc_GetGetLastHitSpellID);
	void __fastcall Npc_GetGetLastHitSpellID(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If the parameter is not valid we return invalid id (-1)
        zCParser* parser = (zCParser*)(*(DWORD*)(reg.esp + 0x14));
        if (reg.esi == reg.ebx)
            parser->SetReturn(-1);
	}

	void __fastcall Npc_GetGetLastHitSpellCat(Union::Registers& reg);
	auto Partial_Npc_GetGetLastHitSpellCat =
        Union::CreatePartialHook(
            reinterpret_cast<void*>(
                zSwitch(0x0,
                        0x0,
                        0x0,
                        0x006e585c)), &Npc_GetGetLastHitSpellCat);
	void __fastcall Npc_GetGetLastHitSpellCat(Union::Registers& reg)
	{
        // Original function does not push a value to the data stack
        // if one of the parameters is not valid
        // If the parameter is not valid we return invalid id (-1)
        zCParser* parser = (zCParser*)(*(DWORD*)(reg.esp + 0x14));
        if (reg.esi == reg.ebx)
            parser->SetReturn(-1);
	}
#endif // ENGINE > 2

#endif
}
