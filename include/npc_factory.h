#include <memory>
#include "npc.h"
#include "elf.h"
#include "knight.h"
#include "druid.h"

class NPCFactory
{
public:
    static std::unique_ptr<NPC> createNPC(const std::string &type, const std::string &name, int x, int y)
    {
        if (type == "Druid")
            return std::make_unique<Druid>(name, x, y);
        if (type == "Elf")
            return std::make_unique<Elf>(name, x, y);
        if (type == "Knight")
            return std::make_unique<Knight>(name, x, y);
        return nullptr;
    }
};