
---@type WBP_Main_C
local WBP_Main = UnLua.Class()

function WBP_Main:Construct()
    self.Overridden.Construct(self)
    local tItems = {
        {strName = "语文", nScore = 90},
        {strName = "数学", nScore = 100},
        {strName = "英语", nScore = 60},
        1,
    }
    ---设置lua_table列表数据(新增)
    self.ByListView_Menu:SetListItems(tItems)

    local tItem = {strName = "语文", nScore = 90}

    ---通过lua_table数据获取UObject数据(新增)
    local tObject = self.ByListView_Menu:GetItemObject(tItems[3])
    print("WBP_Main", tObject.strName) --英语

    ---通过索引(起始0)获取UObject数据(原生)
    tObject = self.ByListView_Menu:GetItemAt(0)
    print("WBP_Main", tObject.strName) --语文
end

return WBP_Main
