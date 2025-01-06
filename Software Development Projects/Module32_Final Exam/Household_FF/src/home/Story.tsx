import React from 'react'

const Story: React.FC = () => {
	return (
		<section className="bg-white dark:bg-gray-900">
			<div className="py-8 px-4 mx-auto max-w-screen-xl lg:py-16">
				<div className="bg-gray-50 dark:bg-gray-800 border border-gray-200 dark:border-gray-700 rounded-lg p-8 md:p-12 mb-8">
					<a href="#" className="bg-blue-100 text-blue-800 text-xs font-medium inline-flex items-center px-2.5 py-0.5 rounded-md dark:bg-gray-700 dark:text-blue-400 mb-2">
					Why Choose Us
					</a>
					<h1 className="text-gray-900 dark:text-white text-3xl md:text-5xl font-extrabold mb-2">Offer Reliable Services For
					Most Mome Services</h1>
					<p className="text-lg font-normal text-gray-500 dark:text-gray-400 mb-6">Proin gravida nibh velit auctor aliquet. sollicitudi lorem quis bibendum auctor, nisi elit consequat ipsum, sagittis sem nibh elit veniam, quis exercitation</p>
					<a href="#" className="inline-flex justify-center items-center py-2.5 px-5 text-base font-medium text-center text-white rounded-lg bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:ring-blue-300 dark:focus:ring-blue-900">
						Read more
						<svg className="w-3.5 h-3.5 ms-2 rtl:rotate-180" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 14 10">
							<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M1 5h12m0 0L9 1m4 4L9 9" />
						</svg>
					</a>
				</div>
				<div className="grid md:grid-cols-2 gap-8">
					<div className="bg-gray-50 dark:bg-gray-800 border border-gray-200 dark:border-gray-700 rounded-lg p-8 md:p-12">
						<a href="#" className="bg-green-100 text-green-800 text-xs font-medium inline-flex items-center px-2.5 py-0.5 rounded-md dark:bg-gray-700 dark:text-green-400 mb-2">
						DreamIT Company
						</a>
						<h2 className="text-gray-900 dark:text-white text-3xl font-extrabold mb-2">Our company is at your
						service at all times</h2>
						<p className="text-lg font-normal text-gray-500 dark:text-gray-400 mb-4">Proin gravida nibh vel velit auctor aliquet. sollicitudi lorem quis bibendum auctor, nisi elit consequat
						Proin gravida nibh vel velit auctor aliquet. sollicitudi lorem quis bibendum auctor, nisi elit consequat</p>
						<a href="#" className="text-blue-600 dark:text-blue-500 hover:underline font-medium text-lg inline-flex items-center">Read more
							<svg className="w-3.5 h-3.5 ms-2 rtl:rotate-180" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 14 10">
								<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M1 5h12m0 0L9 1m4 4L9 9" />
							</svg>
						</a>
					</div>
					<div className="bg-gray-50 dark:bg-gray-800 border border-gray-200 dark:border-gray-700 rounded-lg p-8 md:p-12">
						<a href="#" className="bg-purple-100 text-purple-800 text-xs font-medium inline-flex items-center px-2.5 py-0.5 rounded-md dark:bg-gray-700 dark:text-purple-400 mb-2">
							<svg className="w-2.5 h-2.5 me-1.5" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 20 16">
								<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 4 1 8l4 4m10-8 4 4-4 4M11 1 9 15" />
							</svg>
							Don’t Know What to Start with?
						</a>
						<h2 className="text-gray-900 dark:text-white text-3xl font-extrabold mb-2">Our manager will answer all questions</h2>
						<p className="text-lg font-normal text-gray-500 dark:text-gray-400 mb-4">We accept requests and phone calls 24/7 so you could resolve any problem whenever you need. Our emergency team will be at your place...

</p>
						<a href="#" className="text-blue-600 dark:text-blue-500 hover:underline font-medium text-lg inline-flex items-center">Read more
							<svg className="w-3.5 h-3.5 ms-2 rtl:rotate-180" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 14 10">
								<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M1 5h12m0 0L9 1m4 4L9 9" />
							</svg>
						</a>
					</div>
				</div>
			</div>
		</section>

	)
}

export default Story