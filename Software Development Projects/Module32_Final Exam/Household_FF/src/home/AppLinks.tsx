import React from 'react'

const AppLinks: React.FC = () => {
	return (
		<div className=" bg-gray-900">
			<div className="max-w-2xl mx-auto text-white py-10">
				<div className="text-center">
					<h3 className="text-3xl mb-3"> Download our app </h3>
					<p> Stay Connected. All day, every day. </p>
					<div className="flex justify-center my-10">
						<div className="flex items-center border w-auto rounded-lg px-4 py-2 w-52 mx-2">
							<img src="https://cdn-icons-png.flaticon.com/512/888/888857.png" className="w-7 md:w-8"/>
								<div className="text-left ml-3">
									<p className='text-xs text-gray-200'>Download on </p>
									<p className="text-sm md:text-base"> Google Play Store </p>
								</div>
						</div>
						<div className="flex items-center border w-auto rounded-lg px-4 py-2 w-44 mx-2">
							<img src="https://cdn-icons-png.flaticon.com/512/888/888841.png" className="w-7 md:w-8"/>
								<div className="text-left ml-3">
									<p className='text-xs text-gray-200'>Download on </p>
									<p className="text-sm md:text-base"> Apple Store </p>
								</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	)
}

export default AppLinks