import { createSlice, PayloadAction } from "@reduxjs/toolkit";

interface DashboardState{
	isActive:boolean,
	activeAsideBtn: string
}

const initialState: DashboardState={
	isActive:true,
	activeAsideBtn: 'dashboard'
}

const DashboardSlice=createSlice({
	name:'dashboard',
	initialState,
	reducers:{
		setDashboardBtnActive(state,  action: PayloadAction<boolean>){
			state.isActive = action.payload
		},
		setDashboardAsideBtn(state, action: PayloadAction<string>){
			state.activeAsideBtn= action.payload
		}

	}
})

export const {setDashboardAsideBtn, setDashboardBtnActive} = DashboardSlice.actions;
export default DashboardSlice.reducer;