#include <imgui.h>

#include <Scan.hpp>
#include <Patch.hpp>

#include "Log.hpp"
#include "ShowCombatPower.hpp"

using namespace std;

namespace kanan {
    ShowCombatPower::ShowCombatPower()
        : m_isEnabled{ false },
        m_patch{}
    {
        auto address = scan("client.exe", "0F 85 ? ? ? ? 8B 97 ? ? ? ? 8B 87");

        if (address) {
            log("Got ShowCombatPower %p", *address);

            m_patch.address = *address;
            m_patch.bytes = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
        }
        else {
            log("Failed to find ShowCombatPower address.");
        }
    }

    void ShowCombatPower::onPatchUI() {
        if (m_patch.address == 0) {
            return;
        }

        if (ImGui::Checkbox("Show Combat Power", &m_isEnabled)) {
            apply();
        }
    }

    void ShowCombatPower::onConfigLoad(ConfigPtr cfg) {
        m_isEnabled = cfg->get_qualified_as<bool>("ShowCombatPower.Enabled").value_or(false);

        if (m_isEnabled) {
            apply();
        }
    }

    void ShowCombatPower::onConfigSave(ConfigPtr cfg) {
        auto tbl = cpptoml::make_table();

        tbl->insert("Enabled", m_isEnabled);
        cfg->insert("ShowCombatPower", tbl);
    }

    void ShowCombatPower::apply() {
        if (m_patch.address == 0) {
            return;
        }

        log("Toggling ShowCombatPower...");

        if (m_isEnabled) {
            patch(m_patch);
        }
        else {
            undoPatch(m_patch);
        }
    }
}