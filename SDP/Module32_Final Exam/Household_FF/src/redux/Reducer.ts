
interface AuthState{
	token : string | null
};

const initialState:AuthState={
	token: localStorage.getItem('authToken')
};

export const authReducer=(state = initialState, action: any)=>{
	switch (action.type) {
		case 'SET_AUTH_TOKEN':
			return{
				...state,
				token: action.payload
			};
	
		default:
			return state;
	}
}
