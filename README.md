# zExternalFixes

This Union plugin and `.patch` patch fix data stack problems in external function in all ZenGin versions.

## TODO
- [x] G1
- [ ] G1A
- [ ] G2
- [x] G2A


## Fixed functions
List of all externals that had problems
- `AI_ReadyMeleeWeapon`
- `AI_ReadyRangedWeapon`
- `IntroduceChapter`
- `Tal_Configure`
- `Npc_SetTalentSkill`
- `Npc_SetTalentValue`

- `Npc_GetActiveSpell`
- `Npc_GetActiveSpellCat`
- `Npc_GetActiveSpellLevel`
- `Npc_GetActiveSpellIsScroll`
- `Npc_GetLastHitSpellID`
- `Npc_GetLastHitSpellCat`
- `Npc_GetGuildAttitude`
- `Npc_HasDetectedNpc`
- `Npc_GetAttitude`
- `Npc_GetPermAttitude`
- `Npc_HasSpell`

## Problems
There are few ways these externals corrupt the data stack.
1. Miss-matched external registration  
    - function is registered to push a value as a return, but the implementation does not do that, or vice versa = leaving the stack in unexpected state
    - function is registered with `x` amount of arguments, but the implementation does pop `y` arguments form the data stack, either leaving unwanted values on the stack, or eating values off the stack that were not meant for this function
2. Control flow issues
   - the implementation does not push the return value in one branch of its execution

This causes unexpected behavior in Daedalus, when evaluating conditions or abusing the lack of Daedalus compiler's control flow checks.
