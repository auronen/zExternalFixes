// Helpers

func void a() {};
func int b() { return 1; };
func void p(var int expected) {
     var int s_size = stack_size();
     var int accumulator; // here we doing a little Daedalus trolling :bjorn:
#if 1 {
     var string mes = ConcatStrings(IntToString(accumulator) , ": ");
     mes = ConcatStrings(mes, IntToString(s_size));
     mes = ConcatStrings(mes, " (");
     mes = ConcatStrings(mes, IntToString(expected));
     mes = ConcatStrings(mes, " <- expected)");
     Std_Print(mes);
} else {
     if s_size != expected {
        var string mes = ConcatStrings(IntToString(accumulator), ": ");
        mes = ConcatStrings(mes, "Expected stack is: ");
        mes = ConcatStrings(mes, IntToString(expected));
        mes = ConcatStrings(mes, " real stack is: ");
        mes = ConcatStrings(mes, IntToString(s_size));
        Std_Print(mes);
     };
}
     accumulator += 1;
};

// the body of the checks

#if 1 {
// control
    p(0); // 0: initial stack state
        a(); // good function
    p(0); // 1
        b(); // unhandled return value - leaves crap on the stack
    p(2); // 2

// first block: we are testing all the externals that were polluting the data stack
// implementation is in .patch file
        Npc_SetTalentSkill(hero, 0, 1);
    p(2); // 3
        Npc_SetTalentValue(hero, 0, 1);
    p(2); // 4
        AI_ReadyMeleeWeapon(hero);
    p(2); // 5
        AI_ReadyRangedWeapon(hero);
    p(2); // 6
        IntroduceChapter("", "", "", "", 0);
    p(2); // 7
        // we are not testing tal_configure - it is deprecated, completely invalid and dangerous to use

// next we test calls with invalid/valid params, to validate both code paths actually return something to the stack
        Npc_GetGuildAttitude(NULL, NULL);
    p(4); // 8
        Npc_GetGuildAttitude(self, other);
    p(6); // 9

        Npc_HasDetectedNpc(NULL, NULL);
    p(8);  // 10
        Npc_HasDetectedNpc(self, other);
    p(10); // 11

        Npc_GetPermAttitude(NULL, NULL);
    p(12); // 12
        Npc_GetPermAttitude(self, other);
    p(14); // 11

        Npc_HasSpell(NULL, NULL);
    p(16); // 14
        Npc_HasSpell(self, other);
    p(18); // 15

        Npc_GetActiveSpell(NULL);
    p(20); // 16
        Npc_GetActiveSpell(self);
    p(22); // 17

        Npc_GetActiveSpellCat(NULL,);
    p(24); // 18
        Npc_GetActiveSpellCat(self);
    p(26); // 19

        Npc_GetActiveSpellLevel(NULL,);
    p(28); // 20
        Npc_GetActiveSpellLevel(self);
    p(30); // 21

        Npc_GetAttitude(NULL, NULL);
    p(32); // 22
        Npc_GetAttitude(self, other);
    p(34); // 23
#if __G2A__ {
        Npc_GetActiveSpellIsScroll(NULL);
    p(36); // 24
        Npc_GetActiveSpellIsScroll(item);
    p(38); // 25

        Npc_GetLastHitSpellID(NULL);
    p(40); // 26
        Npc_GetLastHitSpellID(hero);
    p(42); // 27

        Npc_GetLastHitSpellCat(NULL);
    p(44); // 28
        Npc_GetLastHitSpellCat(hero);
    p(46);
}

    // This will have extra element on the stack
    // pushi 46 <- pushed first
    // callx stack_size
    // Std_Print(stack_size() == 46 ? "PASSED" : "FAILED");
    Std_Print(46 == stack_size() ? "PASSED" : "FAILED");
}
