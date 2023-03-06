--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@class WBP_Item : WBP_Item_C
local M = UnLua.Class()

--- 列表数据刷新通知(原生)
function M:OnListItemObjectSet(tItem) --UObject
    self.TextBlock_Content:SetText(string.format("%s: %s", tItem.strName, tItem.nScore))
end

return M
